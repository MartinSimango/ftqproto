#pragma once


#include <vector>
#include "ResponseStatus.hpp"
#include "ResponseFile.hpp"

namespace ftq_usecase  {

    typedef struct {
        std::vector<ResponseFile> files;
        ResponseStatus status;
    } CreateResponse;
}
