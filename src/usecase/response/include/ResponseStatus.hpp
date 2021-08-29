#pragma once

#include <string>


namespace ftq_usecase {

typedef struct {

     enum Status {
        OK = 0,
        FILE_NOT_FOUND = 1,
        NO_WRITE_PERMISSIONS = 2,
        NO_READ_PERMISSIONS = 3,
        FAILED_TO_CREATE_FILE = 4,
        FAILED_TO_CREATE_DIRECTORY = 5,
        OPERATION_NOT_PERMITTED = 6
    };
    
    std::string body;
    Status status;

} ResponseStatus;

}