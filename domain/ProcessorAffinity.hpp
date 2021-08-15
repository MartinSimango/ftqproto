#pragma once

#include "FtqUtil.hpp"
#include <vector>

namespace ftq {
    
    #ifdef linux

    #define _GNU_SOURCE
    #define __USE_GNU
    #include <sched.h>

    typedef cpu_set_t ftq_cpu_set_t;

    #else 

    typedef uint8 ftq_cpu_set_t;

    #endif // linux

    class ProcessorAffinity {
    
  

    public:

        ProcessorAffinity() {}


        static void setProcessAffinity(Process * process);

        // todo implement
        static ftq_cpu_set_t getProcessAffinity();

    };

}


