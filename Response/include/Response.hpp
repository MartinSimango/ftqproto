#pragma once

#include <unistd.h>
#include <ftqproto/Serializer.h>
#include <ftqproto/RequestConstants.hpp>
#include <ftqproto/ResponseException.hpp>
#include <errno.h>

namespace response {

    class Response {
        
        private:
        int fd;


        inline void readMessageLength() {
            unsigned char buffer[sizeof(messageSize)];
            int bytesRead = read(fd, buffer, sizeof(buffer));

            if (bytesRead < 0)
                throw new ResponseException(FAILED_TO_READ_RESPONSE);

            deserialize_int_big_endian(buffer, &messageSize);    
        }

        inline int getMessageSize() {
            return messageSize + sizeof(messageSize); //number of bytes of request will
        }

        inline void deserializeResponseMessage(unsigned char *buffer){
            buffer = deserialize_char_array(buffer, &message[0]);
        }

        inline void deserializeResponseMessageLength(unsigned char *buffer){
            buffer = deserialize_int_big_endian(buffer, &messageSize);
        }

        inline unsigned char * serializeResponse(unsigned char *buffer){
            buffer = serialize_int_big_endian(buffer, messageSize);
            buffer = serialize_char_array(buffer, &message[0]);
            return buffer;
        }
            
        public:

        int messageSize; //size of protobuf message in bytes
        std::string message;

        Response(int fd): fd(fd) { //for reading response
            this->messageSize = -1;
        }

        Response(int fd, std::string message): fd(fd), message(message){  //for writing response
            this->messageSize = message.length() + 1;         
        }

        virtual ~Response() { }
        
        int Write();

        int Read();

    };
};


    




