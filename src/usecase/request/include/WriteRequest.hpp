#pragma once

#include <string>
#include "../../../domain/util/include/FtqUtil.hpp"

namespace ftq_usecase {

    typedef struct 
    {
     std::string filePath;
     std::string data;
     ftq_domain::uint32 offset;

    } WriteRequest;
    
}
