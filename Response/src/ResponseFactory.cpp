#include <ftqproto/ResponseFactory.hpp>

using namespace response;

std::string ResponseFactory::GetSerializedCreateResponse(CreateResponse createResponse) {
    std::string output;
    createResponse.SerializeToString(&output);
    return output;
} 


std::string ResponseFactory::GetSerializedGetResponse(GetResponse getResponse) {
    std::string output;
    getResponse.SerializeToString(&output);
    return output;
} 


std::string ResponseFactory::GetSerializedReadResponse(ReadResponse readResponse) {
    std::string output;
    readResponse.SerializeToString(&output);
    return output;
} 


std::string ResponseFactory::GetSerializedWriteResponse(WriteResponse writeResponse) {
    std::string output;
    writeResponse.SerializeToString(&output);
    return output;
} 