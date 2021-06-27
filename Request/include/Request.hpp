#pragma once

#include <unistd.h>
#include <ftqproto/Serializer.h>
#include <ftqproto/RequestConstants.hpp>
#include <ftqproto/RequestException.hpp>
#include <errno.h>

namespace request {

    class Request {
        
        private:
        int fd;

        inline void readMessageLength() {
            unsigned char buffer[sizeof(messageSize)];
            int bytesRead = read(fd, buffer, sizeof(buffer));

            if (bytesRead < 0)
                throw new RequestException(FAILED_TO_READ_REQUEST);

            if (bytesRead > 0) { //only derialize when something is read
                deserializeRequestMessageLength(buffer);
            }
        
        }

        inline int getMessageSize() {
            return messageSize + sizeof(messageSize); //number of bytes of request will
        }

        inline void deserializeRequestMessage(unsigned char *buffer){
            buffer = deserialize_int_big_endian(buffer, (int*)&requestType);
            char m[messageSize];
            buffer = deserialize_char_array(buffer, m);
            message = std::string(m);
        }

        inline void deserializeRequestMessageLength(unsigned char *buffer){
            buffer = deserialize_int_big_endian(buffer, &messageSize);
        }

        inline unsigned char * serializeRequest(unsigned char *buffer){
            buffer = serialize_int_big_endian(buffer, messageSize);
            buffer = serialize_int_big_endian(buffer, requestType);
            buffer = serialize_char_array(buffer, &message[0]);

            return buffer;
        }
        
        
        public:
            int messageSize; //size of protobuf message in bytes
            RequestType::Type requestType;
            std::string message;

        Request(int fd): fd(fd) { //for reading request
            this->messageSize = 0;
        }

        Request(int fd, std::string message, RequestType::Type requestType): fd(fd), message(message){  //for writing request
            this->messageSize = message.length() + 1 + sizeof(this->requestType);            
            this->requestType = requestType;
        }

        virtual ~Request() { }
        
        int Write();

        int Read();

    };
};


    




