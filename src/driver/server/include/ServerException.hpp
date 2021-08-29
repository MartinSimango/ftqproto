#pragma once
#include <cpperror/ErrorException.hpp>
#include <errno.h>

namespace fts {
    
    static const char * FAILED_TO_BIND_SERVER_SOCKET = "Failed to bind the server socket.";
    static const char * FAILED_TO_CREATE_SERVER_SOCKET = "Failed to create the server socket!";
    static const char * SERVER_FAILED_TO_START_LISTENING = "Server failed to start listening!";
    static const char * SERVER_NOT_RUNNING = "The server is not running!";
    static const char * FAILED_TO_CLOSE_SERVER_SOCKET = "Failed to close the server socket.";
    static const char * FAILED_TO_CLOSE_CLIENT_SOCKET = "Failed to close the server socket.";
    static const char * FAILED_TO_ACCEPT_CONNECTION = "Failed accept connection.";


    class ServerException : public error::ErrorException {
        
        private:
            const char* error;
        
        public:
            ServerException(const char *error) : error::ErrorException(), error(error){
                
            }
            
            const char * what() const throw() override {
                return error;   
            }

            std::string getErrorMessage() override {
                return "[Error] " + std::string(strerror(errno)) + "\n[ServerException] Error: " + this->error; 
            }
    };

}