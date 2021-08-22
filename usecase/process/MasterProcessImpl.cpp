#include "MasterProcessImpl.hpp"

using namespace ftq;

void MasterProcessImpl::run() {
    //todo logger
    Logger::logInfo(getProcessName() + " started");

    startWorkerProcesses(getCpuCount());
    wait(NULL);
}
