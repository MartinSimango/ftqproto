#include <ftqproto/ResponseFactory.hpp>
#include <ftqproto/ResponseException.hpp>

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

ResponseStatus_Status ResponseFactory::GetResponseStatusFromFRWStatus(frw::FileReadWriterStatus status) {
    switch (status)
    {
    case frw::FileReadWriterStatus::OK:
        return ResponseStatus_Status_OK;
    case frw::FileReadWriterStatus::FILE_NOT_FOUND:
        return ResponseStatus_Status_FILE_NOT_FOUND;
    case frw::FileReadWriterStatus::NO_WRITE_PERMISSIONS:
        return ResponseStatus_Status_NO_WRITE_PERMISSIONS;
    case frw::FileReadWriterStatus::NO_READ_PERMISSIONS:
        return ResponseStatus_Status_NO_READ_PERMISSIONS;
    case frw::FileReadWriterStatus::FAILED_TO_CREATE_FILE:
        return ResponseStatus_Status_FAILED_TO_CREATE_FILE;
    case frw::FileReadWriterStatus::FAILED_TO_CREATE_DIRECTORY:
        return ResponseStatus_Status_FAILED_TO_CREATE_DIRECTORY;
    case frw::FileReadWriterStatus::OPERATION_NOT_PERMITTED:
        return ResponseStatus_Status_OPERATION_NOT_PERMITTED;    
    default:
        throw new ResponseException(INVALID_RESPONSE_STATUS);
    }
}
