#pragma once

#include "../../../domain/util/include/FtqUtil.hpp"
#include "ResponseStatus.hpp" 

namespace ftq_usecase {

    typedef struct {
        ftq_domain::uint32 bytesWritten;
        ResponseStatus status; 
        
    }  WriteResponse;

}

