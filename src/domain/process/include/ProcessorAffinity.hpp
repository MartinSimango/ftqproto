#pragma once

#include "../../util/include/FtqUtil.hpp"
#include "../../process/include/Process.hpp"
#include <vector>

namespace ftq_domain {
    
    #ifdef __linux__

    // #define _GNU_SOURCE
    // #define __USE_GNU
    #include <sched.h>

    typedef cpu_set_t ftq_cpu_set_t;

    #else 

    typedef uint8 ftq_cpu_set_t;

    #endif // linux

    class ProcessorAffinity {
    
  

    public:

        ProcessorAffinity() {}

        static void setProcessAffinity(ftq_domain::Process * process);

        static std::vector<uint8> getProcessAffinity(ftq_domain::Process * process);

    };


}

