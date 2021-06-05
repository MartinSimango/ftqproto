#pragma once
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ftqproto/FileReadWriter.hpp>
#include <ftqproto/ClientException.hpp>
#include <ftqproto/Request.hpp>
#include <ftqproto/Response.hpp>

using namespace request;
using namespace response;
using namespace frw;

namespace ftc {


    struct ServerPort {
        char serverAddress[16];
        int port;
    };


    class FileClient {
        
        private:
        bool isConnected, mode;
        int sockfd, fileSize;
        const char * errorMessage;
        char requestFileName[MAX_FILEPATH_LENGTH], filename[MAX_FILEPATH_LENGTH];    

        // TODO be able to have protocol specificied

        // connectToServer to the connects to the server specified by serverPort
        inline void connectToServer(struct ServerPort serverPort) {
            
            struct sockaddr_in servaddr;

            if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
                throw new ClientException(FAILED_TO_CREATE_CLIENT_SOCKET);
            }

            bzero(&servaddr, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr(serverPort.serverAddress);
            servaddr.sin_port = htons(serverPort.port);
            
            if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
                throw new ClientException(FAILED_TO_CONNECT_TO_SERVER);
            }   
        }    

        public:
        FileClient() {}

        ~FileClient() {}

        // Connect connects the client to the specific server specified by the ServerPort 
        // returns false if connect failed and errorMessage is set
        void Connect(struct ServerPort serverPort);
        
        std::string SendCreateRequest(std::string protoRequest);

        std::string SendGetRequest(std::string protoRequest);

        std::string SendReadRequest(std::string protoRequest);

        std::string SendWriteRequest(std::string protoRequest);
       
        // Close closes the connection to the server, returns false upon failure
        void Close();
    };


};

