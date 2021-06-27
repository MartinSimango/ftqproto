#pragma once

#include <ftqproto/CreateResponse.pb.h>
#include <ftqproto/GetResponse.pb.h>
#include <ftqproto/ReadResponse.pb.h>
#include <ftqproto/WriteResponse.pb.h>

namespace response {


    class ResponseFactory
    {
   
    public:
        ResponseFactory(){}
        
        ~ResponseFactory(){}
        
        std::string GetSerializedCreateResponse(CreateResponse createResponse);

        std::string GetSerializedGetResponse(GetResponse getResponse);
        
        std::string GetSerializedReadResponse(ReadResponse readResponse);
        
        std::string GetSerializedWriteResponse(WriteResponse writeResponse);    
                
    };



}