#pragma once

#include <ftqproto/FileReadWriterConstants.hpp>
#include <ftqproto/Request.hpp>

namespace request {

    class WriteRequest : public request::Request
    {
      
    public:
        int offset, numberOfBytesToWrite;
        char data[MAX_BUFFER_SIZE], filepath[MAX_FILEPATH_LENGTH];

        WriteRequest(int fd, char* data, int offset, int numberOfBytesToWrite, char* filepath): request::Request(fd) {
            if (numberOfBytesToWrite > MAX_BUFFER_SIZE) {
                numberOfBytesToWrite = MAX_BUFFER_SIZE;
            }

            strncpy(this->data, data, sizeof(this->data));

            strncpy(this->filepath, filepath, sizeof(this->filepath));

            requestType = RequestType::READ;
            this->offset = offset;
            this->numberOfBytesToWrite = numberOfBytesToWrite;
        }

        WriteRequest(int fd, RequestHeader * requestHeader): request::Request(fd) {
            requestType = RequestType::WRITE;

            delete this->header;
            this->header = requestHeader;
        }

        ~WriteRequest(){}

        int getRequestBodySize() const override;

        void deserializeRequestBody(unsigned char *buffer) override;

        unsigned char * serializeRequestBody(unsigned char *buffer) override;

        std::string GetBody() const override;


    };

}