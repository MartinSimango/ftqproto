#pragma once

#include <cpperror/ErrorException.hpp>
#include <ftqproto/ResponseConstants.hpp>
#include <errno.h>


static const char * FAILED_TO_WRITE_RESPONSE = "Failed to write response.";
static const char * FAILED_TO_READ_RESPONSE = "Failed to read response.";
static const char * INVALID_RESPONSE_STATUS = "Invalid response status";



namespace response {

    class ResponseException : public error::ErrorException {
        
        private:
            const char* error;
        
        public:
            ResponseException(const char *error) : error::ErrorException(), error(error){}
            
            const char * what() const throw() override {
                return error;   
            }

            
            std::string getErrorMessage() override {
                return "[Error] " + std::string(strerror(errno)) + "\n[ResponseException] Error: " + this->error;
            }

    };

}