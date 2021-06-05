#include <ftqproto/Client.hpp>
#include <ftqproto/Request.hpp>
#include <ftqproto/Responses.hpp>

using namespace ftc;
using namespace request;

void FileClient::Connect(struct ServerPort serverPort) {
    if (isConnected)
        throw new ClientException(CLIENT_ALREADY_CONNECTED);
    
    connectToServer(serverPort);
    isConnected = true;
}


GetResponse FileClient::SendGetRequest(char * filepath){
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);

    GetRequest request(sockfd, filepath);
    GetResponse response(sockfd);

    request.Write();
    return response;
}

CreateResponseStruct FileClient::SendCreateRequest(std::string protoRequest) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);


    Request request(sockfd, protoRequest, RequestType::CREATE);
    Response response(sockfd);
    response.Read();

    response.m


    createResponse.numFiles = response.numFiles;
    createResponse.fileSizes = new int[response.numFiles];
    createResponse.filenames = new char*[response.numFiles];
    createResponse.isDirs = new bool[response.numFiles];

    for (int i = 0; i< response.numFiles; i++) {
        createResponse.filenames[i] = new char[MAX_FILEPATH_LENGTH];
        strncpy(createResponse.filenames[i],response.files->at(i).filename, MAX_FILEPATH_LENGTH);
        createResponse.fileSizes[i] = response.files->at(i).fileSize;
        createResponse.isDirs[i] = response.files->at(i).isDir;
    }
    
    return createResponse;
}

ReadResponse FileClient::SendReadRequest(int numberOfBytesToRead, int offset, char *readFile, char * writeFile) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);
    
    ReadRequest request(sockfd, readFile, offset, numberOfBytesToRead);
    ReadResponse response(sockfd);

    request.Write();
    response.Read();

    FileReadWriter frw(writeFile, Mode::WRITE);
    frw.Open();
    frw.WriteToFile(response.data, response.numberOfBytesRead, offset);
    frw.Close();

    return response;
}

WriteResponse FileClient::SendWriteRequest(int numberOfBytesToWrite, int offset, char *readFile, char * writeFile) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);

    FileReadWriter frw(readFile, Mode::READ);
    frw.Open();
    int bytes_written = writeToServer(&frw, writeFile, numberOfBytesToWrite, offset);
    frw.Close();

    WriteResponse response(sockfd);
    response.Read();

    return response;
}


void FileClient::Close() {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);
    if (close(sockfd) < 0) 
        throw new ClientException(FAILED_TO_CLOSE_CLIENT_SOCKET);

    isConnected = false;
}