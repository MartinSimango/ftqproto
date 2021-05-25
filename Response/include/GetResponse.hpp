#pragma once
#include <ftqproto/Response.hpp>
#include <ftqproto/CreateRequest.hpp>
#include <ftqproto/FileReadWriterConstants.hpp>

namespace response {

    class GetResponse: public Response
    {
    private:
        std::vector<request::File> * files;
        int numFiles;
    public:
        GetResponse(int fd): Response(fd) {
            responseType = ResponseType::GET;
        }

        GetResponse(int fd, std::vector<request::File> * files, ResponseStatus::Type status = ResponseStatus::OK): Response(fd), files(files) {
            responseType = ResponseType::GET;
            this->numFiles = files->size();
            this->status = status;
        }

        ~GetResponse(){};
        
        int getResponseBodySize() const override;

        void deserializeResponseBody(unsigned char *buffer) override;

        unsigned char * serializeResponseBody(unsigned char *buffer) override;

        std::string GetBody() const override;

    };

}

