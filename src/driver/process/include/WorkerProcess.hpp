#pragma once

#include "../../../domain/process/include/Process.hpp"
#include "../../../domain/util/include/FtqUtil.hpp"
#include <pthread.h>
#include <string>

namespace ftq_driver {

class WorkerProcess : public ftq_domain::Process {

  private:
	pthread_mutex_t *socketMutexLock;

  public:
	WorkerProcess(std::string processName, ftq_domain::ftq_pid_t pid, ftq_domain::uint8 cpuId,
				  pthread_mutex_t *socketMutexLock)
		: ftq_domain::Process(processName, ftq_domain::ProcessType::WORKER_PROCESS, pid, cpuId),
		  socketMutexLock(socketMutexLock) {}

	void run() override;

	// used for testing
	bool operator==(const WorkerProcess process) {
		return process.pid == this->pid && process.processName == this->processName &&
			   process.processType == this->processType && process.cpuSet == this->cpuSet;
	}

	bool operator!=(const WorkerProcess process) { return !(*this == process); }
};

}; // namespace ftq_driver