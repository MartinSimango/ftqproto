#include "WorkerProcess.hpp"
#include <stdio.h>

using namespace ftq;

void WorkerProcess::run() {

    Logger::logInfo(getProcessName() + " started");
    for(;;) {
        #ifdef linux
        printf("Worker process %s on Processor %i\n",process.process_name, sched_getcpu());
        #endif
    }
}