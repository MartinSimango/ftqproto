#pragma once

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ftqproto/FileReadWriter.hpp>
#include <sys/stat.h>
#include <string>
#include <ftqproto/ServerException.hpp>
#include <sys/ioctl.h>
#include <libgen.h>
#include <ftqproto/Request.hpp>
#include <ftqproto/Response.hpp>
#include <ftqproto/CreateRequest.pb.h>
#include <ftqproto/CreateResponse.pb.h>
#include <ftqproto/GetRequest.pb.h>
#include <ftqproto/GetResponse.pb.h>
#include <ftqproto/ReadRequest.pb.h>
#include <ftqproto/ReadResponse.pb.h>
#include <ftqproto/WriteRequest.pb.h>
#include <ftqproto/WriteResponse.pb.h>
#include <ftqproto/ResponseFactory.hpp>
#include <ftqproto/RequestFactory.hpp>
#include <functional>

using namespace request;
using namespace response;
using namespace frw;

//TODO find duplicated methods in Server and Client and make that method in shared class
namespace fts {

    struct ServerPort {
        char serverAddress[16];
        int port;
    };

    // TODO if error occurs sent request back to client

    class FileServer {
        
        private:

            int sockfd, connfd, port;
            Mode::Type mode;
            bool isRunning;
            char filepath[MAX_FILEPATH_LENGTH], rootFolder[20]; // TODO make 20 constant
            RequestFactory requestFactory;
            ResponseFactory responseFactory;
            // TODO be able to have protocol specificied
            inline void bindServerSocketAddress() {
                struct sockaddr_in servaddr;

                servaddr.sin_family = AF_INET;
                servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //allow all address to connect
                servaddr.sin_port = htons(port);
                if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) 
                    throw new ServerException(FAILED_TO_BIND_SERVER_SOCKET);
            }

            // createAndBindServerSocket creates the server socket and binds the socket
            inline void createAndBindServerSocket() {
                if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
                    throw new ServerException(FAILED_TO_CREATE_SERVER_SOCKET);
                bindServerSocketAddress();
            }    


          
            inline std::string getDestitionFilePath(std::string destinationPathFile) {
                std::string filepath = std::string(this->rootFolder) + destinationPathFile;
                filepath = std::string(dirname(&filepath[0])) + "/" + std::string(basename(&filepath[0]));
                return filepath;

            }
            
            void setResponseStatus(ResponseStatus *responseStatus, ResponseStatus_Status status, std::string filepath) {
                if (status == ResponseStatus_Status_OK) {
                    responseStatus->set_body(response::ResponseStatus_Status_Name<int>(status));
                }
                else {
                    FRWException e(response::ResponseStatus_Status_Name<int>(status), filepath);
                    responseStatus->set_body(e.getErrorMessage());
                }
        
                responseStatus->set_status(status);
            }

            ResponseStatus* handleDestinationFilePathError(ResponseStatus_Status status, std::string destFile) {
                if (status == ResponseStatus_Status_FILE_NOT_FOUND) { //parent dir did not exist
                        destFile = std::string(dirname(&destFile[0]));
                }
                ResponseStatus *responseStatus = new ResponseStatus();
                setResponseStatus(responseStatus, status, destFile);
                return responseStatus;
            
            }

         
            std::vector<ResponseFile> createFilesInDirectory(CreateRequest request, std::string directoryFilePath) {
                std::vector<ResponseFile> responseFiles;
                
                for (int i = 0; i < request.files_size(); i++) {
                    RequestFile currentFile = request.files(i);

                    ResponseFile rFile;
                    bool copyResult = currentFile.isdir() ? FileReadWriter::CopyDirectoryIntoDirectory(directoryFilePath, currentFile.sourcefilepath())
                                                          : FileReadWriter::CopyFileIntoDirectory(directoryFilePath, currentFile.sourcefilepath(), currentFile.filesize());

                    ResponseStatus_Status status = ResponseStatus_Status_OK;
                    if (!copyResult) {
                        status = currentFile.isdir()? ResponseStatus_Status_FAILED_TO_CREATE_DIRECTORY : ResponseStatus_Status_FAILED_TO_CREATE_FILE;
                    }

                    std::shared_ptr<ResponseStatus> responseStatus = std::make_shared<ResponseStatus>(); //todo use shared pointer
                    setResponseStatus(responseStatus.get(), status, currentFile.sourcefilepath());

                    rFile.set_sourcefilepath(currentFile.sourcefilepath());
                    rFile.set_allocated_status(responseStatus.get());
                    responseFiles.push_back(rFile);

                }
                return responseFiles;
                
            }

            ResponseStatus_Status renameDestinationFilePath(CreateRequest request, std::string destinationFilePath) {
                if(request.issourcedirectory()) {
                    return ResponseStatus_Status_OPERATION_NOT_PERMITTED;
                }
                else {
                    std::string newSourcePath = std::string(dirname(&destinationFilePath[0])) + "/" + request.sourcefilepath();
                    if (!FileReadWriter::RenameFile(destinationFilePath, newSourcePath) 
                        && FileReadWriter::CreateFile(newSourcePath.c_str(), request.files(0).filesize()) ) {
                        return ResponseStatus_Status_FAILED_TO_CREATE_FILE;
                    }
                    return ResponseStatus_Status_OK;
                }
                    
                
            }

            void handleCreateRequest(CreateRequest request) {
                response::ResponseStatus *responseStatus = new ResponseStatus();

                response::CreateResponse createResponse;
                std::vector<ResponseFile> responseFiles;  
                
                std::string destinationFilePath = getDestitionFilePath(request.destinationfilepath());

                std::cout << "File: " << destinationFilePath <<std::endl;

                response::ResponseStatus_Status status = FileReadWriter::CheckFile(destinationFilePath.c_str(), Mode::WRITE);

                if (status == ResponseStatus_Status_OK) {
                    //todo rename method to CheckFilePathIsDir...
                    if (FileReadWriter::CheckFileIsDirectory(destinationFilePath.c_str())) {
                        responseFiles = createFilesInDirectory(request, destinationFilePath);
                    }   
                    else {
                       status = renameDestinationFilePath(request, destinationFilePath);
                    }
                    setResponseStatus(responseStatus, status, request.sourcefilepath());

                }
                else {
                    responseStatus = handleDestinationFilePathError(status, destinationFilePath);
                }


                createResponse.set_allocated_status(responseStatus);
                std::for_each(std::begin(responseFiles), std::end(responseFiles),[&createResponse](ResponseFile file) {
                        createResponse.add_files()->CopyFrom(file);
                });

                Response response(connfd, responseFactory.GetSerializedCreateResponse(createResponse));
                response.Write();

                delete responseStatus;            
            
            }


        void handleGetRequest(GetRequest request) {
                // todo: to implement
        }

        void handleReadRequest(ReadRequest request){

            std::string readFile = std::string(this->rootFolder) + request.filepath();

            FileReadWriter frw(filepath, Mode::READ);
            int numberOfBytesToRead = request.numberofbytestoread();
            int offset = request.offset();
            char buffer[numberOfBytesToRead];

            response::ResponseStatus_Status status = FileReadWriter::CheckFile(filepath, Mode::READ);
            int bytesRead = 0;
            if (status == ResponseStatus_Status_OK) {
                frw.Open();
                bytesRead = frw.ReadFromFile(buffer, numberOfBytesToRead, offset);
                frw.Close();
            }

            
            std::string output;
            response::ReadResponse readReponse;

            readReponse.set_data(std::string(buffer));
            readReponse.SerializeToString(&output);


            Response response(connfd, output);
            response.Write();
        }

        void handleWriteRequest(WriteRequest request){
           
            std::string writeFile = std::string(this->rootFolder) + request.filepath();

            FileReadWriter frw(filepath, Mode::WRITE);
            int offset = request.offset();
            
            int bytesWritten = 0;
            ResponseStatus_Status status = FileReadWriter::CheckFile(filepath, Mode::WRITE);
            if (status == ResponseStatus_Status_OK) {
                frw.Open();
                bytesWritten = frw.WriteToFile(offset, request.data().c_str()); 
                frw.Close();
            }            

            std::string output;
            response::WriteResponse writeReponse;

            writeReponse.set_byteswritten(bytesWritten);
            writeReponse.SerializeToString(&output);

            Response response(connfd, output);
            response.Write();

        }
            
        public:

        // ServerPort represent the server the 
        FileServer(int port, const char * rootFolder = ""): port(port) { 
            strncpy(this->rootFolder, rootFolder, sizeof(this->rootFolder));
        }

        ~FileServer() { }

        // StartServer
        void StartServer(int connections);

        void Accept();

        bool HandleClientRequest();

        bool IsServerRunning();

        void Close();

    };

};

