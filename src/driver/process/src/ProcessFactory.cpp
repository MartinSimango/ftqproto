#include "../include/ProcessFactory.hpp"
#include <pthread.h>

using namespace ftq_driver;

WorkerProcess *ProcessFactory::createWorkerProcess(std::string name, ftq_domain::uint8 cpuId,
												   pthread_mutex_t *socketMutexLock) {
	return new WorkerProcess(name, getpid(), cpuId, socketMutexLock);
}