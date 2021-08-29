#pragma once

#include <vector>
#include "ResponseStatus.hpp"
#include "../../request/include/RequestFile.hpp"


namespace ftq_usecase  {

    typedef struct {
        std::vector<RequestFile> files;
        ResponseStatus status;
    } GetResponse;
}
