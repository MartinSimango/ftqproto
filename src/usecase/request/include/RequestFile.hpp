#pragma once

#include <string>
#include "../../../domain/util/include/FtqUtil.hpp"

namespace ftq_usecase {

    typedef struct 
    {
     std::string sourceFilePath;
     ftq_domain::uint32 fileSize;
     bool isDir;

    } RequestFile;
    
}

