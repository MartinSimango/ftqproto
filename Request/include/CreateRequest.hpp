#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ftqproto/Request.hpp>
#include <ftqproto/FileReadWriterConstants.hpp>

namespace request {

    struct File
    {
        char sourceFilePath[MAX_FILEPATH_LENGTH];        
        int fileSize;
        bool isDir;


        int getSize() {
            return strlen(sourceFilePath) + 1 + sizeof(fileSize) + sizeof(isDir);
        }

        void setSourceFilePath(char * filePath){
            strncpy(this->sourceFilePath, filePath, sizeof(this->sourceFilePath));
        }

        unsigned char * deserializeRequestFile(unsigned char *buffer){
            buffer = deserialize_char_array(buffer, sourceFilePath);
            buffer = deserialize_int_big_endian(buffer, &fileSize); 
            buffer = deserialize_char(buffer, (char *)&isDir);
            return buffer;

        }

        unsigned char * serializeRequestFile(unsigned char *buffer) {
            buffer = serialize_char_array(buffer, sourceFilePath);
            buffer = serialize_int_big_endian(buffer, fileSize);
            buffer = serialize_char(buffer, isDir);
            return buffer;
        }

    };

    class CreateRequest : public Request
    {


    public:

        std::vector<request::File> * files;
        char destinationFilePath[MAX_FILEPATH_LENGTH];        

        int numFiles;

        CreateRequest(int fd, std::vector<request::File> * files, char * destinationFilePath): request::Request(fd), files(files) {
            this->requestType = RequestType::CREATE;
            this->numFiles = files->size();
            strncpy(this->destinationFilePath, destinationFilePath, sizeof(this->destinationFilePath));

        }

        CreateRequest(int fd, RequestHeader * requestHeader): request::Request(fd){
            this->requestType = RequestType::CREATE;

            delete this->header;
            this->header = requestHeader;
        }


        ~CreateRequest(){}

        int getRequestBodySize() const override;

        void deserializeRequestBody(unsigned char *buffer) override;

        unsigned char * serializeRequestBody(unsigned char *buffer) override;

        std::string GetBody() const override;

    };

}
