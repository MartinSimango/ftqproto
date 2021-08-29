#include "../include/WorkerProcess.hpp"
#include <stdio.h>

using namespace ftq_usecase;
using namespace ftq_domain;


void WorkerProcess::run() {

    Logger::logInfo(this->toString() + " started");
    for(;;) {
        #ifdef __linux__
        //todo use logger
        std::cout << this->toString() << " on Processor " << sched_getcpu() << std::endl;
        #endif
    }
}