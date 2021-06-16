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
                ioctl(sockfd, FIONBIO, 0);
                bindServerSocketAddress();
            }    

            CreateRequest createCreateRequest(const char * protoRequestMessage) {
                CreateRequest request;

                request.ParseFromString(protoRequestMessage);
                return request;
            }

            GetRequest createGetRequest(const char * protoRequestMessage) {
                GetRequest request;
                request.ParseFromString(protoRequestMessage);
                return request;
            }

            ReadRequest createReadRequest(const char * protoRequestMessage) {
                ReadRequest request;
                request.ParseFromString(protoRequestMessage);
                return request;

            }

            WriteRequest createWriteRequest(const char *  protoRequestMessage) {
                WriteRequest request;
                request.ParseFromString(protoRequestMessage);
                return request;
            }


            void handleRequest(CreateRequest request) {
                response::CreateResponse createResponse;
                request::RequestFiles filesCreated;
                response::ResponseStatus *responseStatus = new response::ResponseStatus();
                

        
                //check if we can write to destination path
                std::string destFile = std::string(this->rootFolder) + request.destinationfilepath();
                    std::cout << "File: " << destFile <<std::endl;

                response::ResponseStatus_Status status = FileReadWriter::CheckFile(destFile.c_str(), Mode::WRITE);


                if (status != ResponseStatus_Status_OK) { 
                    if (status == ResponseStatus_Status_FILE_NOT_FOUND) { //parent dir did not exist
                        destFile = std::string(dirname(&destFile[0]));
                    }
                    FRWException e(response::ResponseStatus_Status_Name<int>(status), destFile);
                    responseStatus->set_body(e.getErrorMessage());
                    responseStatus->set_status(status);
                    createResponse.set_allocated_status(responseStatus);
                    std::string output;
                    createResponse.SerializeToString(&output);
                    response::Response response(connfd, output);
                    response.Write();
                    return;
                }

                bool isDestDir = FileReadWriter::CheckFileIsDirectory(destFile.c_str());
                request::RequestFile currentFile = request.files(0);
                request::RequestFile *fileToAdd;
                if(isDestDir) {
                    //copy everything in
                    std::string sourceFile = currentFile.sourcefilepath();
                    std::string newSourcePath = std::string(dirname(&destFile[0])) + "/" + std::string(basename(&destFile[0])) + "/" + sourceFile;

                    if (currentFile.isdir()) { 
                        if (!FileReadWriter::DoesFileExist(newSourcePath)) {
                            FileReadWriter::CreateDirectory(newSourcePath.c_str());
                        }
                    }
                    else {
                        FileReadWriter::CreateFile(newSourcePath.c_str(), currentFile.filesize());
                    }
                    createResponse.add_files()->CopyFrom(currentFile);

                }
                else { //isDestDir is a file

                    if (currentFile.isdir()) { //can't copy dir to file
                        std::string err = currentFile.sourcefilepath() + " is a directory (not copied)";
                        status = ResponseStatus_Status_FAILED_TO_CREATE_DIRECTORY;
                        FRWException e(response::ResponseStatus_Status_Name<int>(status), destFile);
                        responseStatus->set_body(e.getErrorMessage());
                        responseStatus->set_status(status);
                        createResponse.set_allocated_status(responseStatus);
                        std::string output;
                        createResponse.SerializeToString(&output);
                        response::Response response(connfd, output);
                        response.Write();
                        return;
                      //  throw new FRWException(err.c_str(), currentFile.sourcefilepath().c_str());
                    }
                    std::string sourceFile = currentFile.sourcefilepath();
                    std::string newSourcePath = std::string(dirname(&destFile[0])) + "/" + std::string(basename(&destFile[0]));
                    FileReadWriter::RenameFile(destFile, newSourcePath);
                    FileReadWriter::CreateFile(newSourcePath.c_str(), currentFile.filesize());

                    createResponse.add_files()->CopyFrom(currentFile); 

                    std::string output;
                    createResponse.SerializeToString(&output);
                    response::Response response(connfd, output);
                    response.Write();

                    return;
                }
              
                
                 // create all the files client has requested to make
                 // destDir is dir and so  was currentfile copy every thing into it
                for (int i= 1; i < request.files_size(); i++) {
                    //
                    currentFile = request.files(i);

                    std::string sourceFile = currentFile.sourcefilepath();
                    std::string newSourcePath = std::string(dirname(&destFile[0])) + "/" + std::string(basename(&sourceFile[0]));
                    if (currentFile.isdir()) { 
                        if (!FileReadWriter::DoesFileExist(newSourcePath)) {
                            FileReadWriter::CreateDirectory(newSourcePath.c_str());
                        }
                    }
                    else {
                        FileReadWriter::CreateFile(newSourcePath.c_str(), currentFile.filesize()); 
                    }
                    
                    createResponse.add_files()->CopyFrom(currentFile);
                }

                std::string output;
                createResponse.SerializeToString(&output);
                response::Response response(connfd, output);
                response.Write();
                
            }

            void handleRequest(GetRequest request) {
                // todo: to implement
            }

            void handleRequest(ReadRequest request){

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

            void handleRequest(WriteRequest request){
           
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
                response::WriteReponse writeReponse;

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

