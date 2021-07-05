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

RequestFile RequestFactory::CreateRequestFileFromFRWFile(frw::File file) {
    RequestFile requestFile;
    requestFile.set_sourcefilepath(file.filepath);
    requestFile.set_filesize(file.fileSize);
    requestFile.set_isdir(file.isDir);

    return requestFile;
}
