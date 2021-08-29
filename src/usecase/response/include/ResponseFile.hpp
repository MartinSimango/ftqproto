#pragma once

#include <string>
#include "ResponseStatus.hpp"

namespace ftq_usecase  {

    typedef struct {
        std::string sourceFilePath;
        ResponseStatus status;

    } ResponseFile;
}


