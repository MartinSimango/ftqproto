#pragma once

#include <string>
#include <vector>
#include "RequestFile.hpp"

namespace ftq_usecase {

    typedef struct 
    {

        std::string sourceFilePath;
        std::string destinationFilePath;
        bool isSourceDirectory;
        std::vector<RequestFile> files;
        /* data */
    } CreateRequest;
    
}


