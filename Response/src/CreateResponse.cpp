#include <ftqproto/CreateResponse.hpp>

using namespace response;

int CreateResponse::getResponseBodySize() const {
    int fileSize = 0;
    for (int i = 0; i < numFiles; i++) {
        fileSize += files->at(i).getSize();
    }
    return fileSize + sizeof(numFiles);
}

void CreateResponse::deserializeResponseBody(unsigned char *buffer){
    
    buffer = deserialize_int_big_endian(buffer, &numFiles);
    delete this->files;
    files = new std::vector<request::File>(numFiles);
    
    for (int i = 0; i < numFiles; i++) {
        buffer = files->at(i).deserializeRequestFile(buffer);
    }
}

unsigned char * CreateResponse::serializeResponseBody(unsigned char *buffer){
        
    buffer = serialize_int_big_endian(buffer, numFiles);

    for (int i = 0; i < numFiles; i++) {
        buffer = files->at(i).serializeRequestFile(buffer);
    }
    return buffer; 
}

std::string CreateResponse::GetBody() const {
    return "{ }";
}
