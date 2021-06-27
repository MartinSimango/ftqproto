#include <ftqproto/RequestFactory.hpp>

using namespace request;

CreateRequest RequestFactory::CreateCreateRequest(const char * protoRequestMessage) {
    CreateRequest request;
    request.ParseFromString(protoRequestMessage);
    return request;
}

GetRequest RequestFactory::CreateGetRequest(const char * protoRequestMessage) {
    GetRequest request;
    request.ParseFromString(protoRequestMessage);
    return request;
}

ReadRequest RequestFactory::CreateReadRequest(const char * protoRequestMessage) {
    ReadRequest request;
    request.ParseFromString(protoRequestMessage);
    return request;

}

WriteRequest RequestFactory::CreateWriteRequest(const char * protoRequestMessage) {
    WriteRequest request;
    request.ParseFromString(protoRequestMessage);
    return request;
}