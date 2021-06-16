#include <ftqproto/Request.hpp>

using namespace request;

int Request::Write() {


    unsigned char buffer[getMessageSize()]; 
    unsigned char *ptr; 

    ptr = serializeRequest(buffer);

    int bytes_written = write(fd, buffer, ptr - buffer);   

    if (bytes_written < 0) {
        throw new RequestException(FAILED_TO_WRITE_REQUEST);
    }
    
    return bytes_written;
}



int Request::Read(){

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
        throw new RequestException(FAILED_TO_READ_REQUEST);
        delete [] buffer;
    }

    deserializeRequestMessage(buffer);

    delete [] buffer;

    return totalBytesRead;
}

