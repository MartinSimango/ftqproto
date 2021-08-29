#pragma once

#include <string>
#include "ResponseStatus.hpp"

namespace ftq_usecase  {

    typedef struct {
        std::string data;
        ResponseStatus status;
    } ReadResponse;
}
