#pragma once

#include <string>
#include "../../../domain/util/include/FtqUtil.hpp"

namespace ftq_usecase {

    typedef struct 
    {
     std::string filePath;
     ftq_domain::uint32 numberOfBytesToRead;
     ftq_domain::uint32 offset;

    } ReadRequest;
    
}


