#pragma once

#include <cpperror/ErrorException.hpp>
#include <ftqproto/RequestConstants.hpp>
#include <errno.h>

static const char * FAILED_TO_WRITE_REQUEST = "Failed to write request.";
static const char * FAILED_TO_READ_REQUEST = "Failed to read from request.";
static const char * FAILED_TO_WRITE_REQUEST_HEADER = "Failed to write request header.";
static const char * FAILED_TO_READ_REQUEST_HEADER = "Failed to read request header.";


namespace request {

    class RequestException : public error::ErrorException {
        
        private:
            const char* error;
        
        public:
            RequestException(const char *error) : error::ErrorException(), error(error) {}
            
            const char * what() const throw() override {
                return error;   
            }


            std::string getErrorMessage() override {
                return "[Error] " + std::string(strerror(errno)) + "\n[RequestException] Error: " + this->error;
                     
            }

    };

}