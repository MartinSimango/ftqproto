#include <ftqproto/Client.hpp>
#include <ftqproto/Request.hpp>

using namespace ftc;
using namespace request;

void FileClient::Connect(struct ServerPort serverPort) {
    if (isConnected)
        throw new ClientException(CLIENT_ALREADY_CONNECTED);
    
    connectToServer(serverPort);
    isConnected = true;
}


std::string FileClient::SendGetRequest(std::string protoRequest){
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);

    Request request(sockfd, protoRequest, RequestType::GET);
    request.Write();
    
    Response response(sockfd);
    response.Read();

    return response.message;
}

std::string FileClient::SendCreateRequest(std::string protoRequest) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);


    Request request(sockfd, protoRequest, RequestType::CREATE);
    request.Write();

    Response response(sockfd);
    response.Read();

    return response.message;
}

std::string FileClient::SendReadRequest(std::string protoRequest) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);
    
    Request request(sockfd, protoRequest, RequestType::READ);
    request.Write();

    Response response(sockfd);
    response.Read();

    return response.message;
}

std::string FileClient::SendWriteRequest(std::string protoRequest) {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);

    Request request(sockfd, protoRequest, RequestType::WRITE);
    request.Write();

    Response response(sockfd);
    response.Read();

    return response.message;
}


void FileClient::Close() {
    if (!isConnected)
        throw new ClientException(CLIENT_NOT_CONNECTED);
    if (close(sockfd) < 0) 
        throw new ClientException(FAILED_TO_CLOSE_CLIENT_SOCKET);

    isConnected = false;
}