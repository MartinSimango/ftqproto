#include "../include/WorkerProcess.hpp"
#include <stdio.h>

using namespace ftq_driver;
using namespace ftq_domain;

void WorkerProcess::run() {

	Logger::logInfo(this->toString() + " started");

	pthread_mutex_lock(socketMutexLock);

	Logger::logInfo(this->toString() + " has socket lock");
	Logger::logInfo(this->toString() + " has released the socket lock");

	for (;;) {
#ifdef __linux__
		// // todo use logger
		// std::cout << this->toString() << " on
		// Processor " << sched_getcpu()
		//           << std::endl;
#endif
	}
}