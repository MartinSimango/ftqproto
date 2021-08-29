#include "../include/MasterProcessImpl.hpp"
#include <sys/wait.h>

using namespace ftq_usecase;
using namespace ftq_domain;


void MasterProcessImpl::run() {
    //todo logger
    Logger::logInfo(this->toString() + " started!");

    startWorkerProcesses(getCpuCount());

    for (uint8 i = 0; i < getCpuCount(); i++) {
            wait(NULL);
    }
    Logger::logInfo(getProcessName() + " ended!");

}
