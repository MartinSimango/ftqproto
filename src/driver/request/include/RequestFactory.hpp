#pragma once

#include <ftqproto/CreateRequest.pb.h>
#include <ftqproto/GetRequest.pb.h>
#include <ftqproto/ReadRequest.pb.h>
#include <ftqproto/WriteRequest.pb.h>
#include <ftqproto/FileReadWriter.hpp>

namespace ftq_driver {


    class RequestFactory
    {
   
    public:
        RequestFactory() {}
        
        ~RequestFactory(){}

        CreateRequest CreateCreateRequest(const char * protoRequestMessage);

        GetRequest CreateGetRequest(const char * protoRequestMessage);
                
        ReadRequest CreateReadRequest(const char * protoRequestMessage);
                
        WriteRequest CreateWriteRequest(const char * protoRequestMessage);

        RequestFile CreateRequestFileFromFRWFile(frw::File file);
                
    };



}