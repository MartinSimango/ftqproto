#include <ftqproto/Response.hpp>

using namespace response;

int Response::Write() {


    unsigned char buffer[getMessageSize()]; 
    unsigned char *ptr; 

    ptr = serializeResponse(buffer);

    int bytes_written = write(fd, buffer, ptr - buffer);   

    if (bytes_written < 0) {
        throw new ResponseException(FAILED_TO_WRITE_RESPONSE);
    }

    return bytes_written;
}

int Response::Read(){

    readMessageLength();

    unsigned char tmp_buffer[messageSize];
    unsigned char* buffer = new unsigned char[messageSize]; 
    
    int bytesRead;
    int totalBytesRead = 0;
    while (totalBytesRead < messageSize && (bytesRead = read(fd, tmp_buffer, messageSize) ) > 0) {
        for (int i =0; i <bytesRead ;i++){
            buffer[totalBytesRead + i] = tmp_buffer[i];
        }
        totalBytesRead += bytesRead;
    }
   

    if (bytesRead < 0)  {
        throw new ResponseException(FAILED_TO_READ_RESPONSE);
        delete [] buffer;
    }
    
    deserializeResponseMessage(buffer);

    delete [] buffer;

    return totalBytesRead; 
}

