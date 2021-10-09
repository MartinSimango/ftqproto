#include "../include/ProcessFactory.hpp"

using namespace ftq_driver;

WorkerProcess *ProcessFactory::createWorkerProcess(std::string name,
                                                   ftq_domain::uint8 cpuId) {
  return new WorkerProcess(name, getpid(), cpuId);
}