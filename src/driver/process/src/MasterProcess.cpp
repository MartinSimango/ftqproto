#include "../include/MasterProcess.hpp"
#include <sys/wait.h>

using namespace ftq_driver;
using namespace ftq_domain;

void MasterProcess::run() {
  // todo logger
  Logger::logInfo(this->toString() + " started!");

  startWorkerProcesses(getCpuCount());

  for (uint8 i = 0; i < getCpuCount(); i++) {
    wait(NULL);
  }
  Logger::logInfo(getProcessName() + " ended!");
}

uint8 MasterProcess::getCpuCount() { return cpuCount; }
