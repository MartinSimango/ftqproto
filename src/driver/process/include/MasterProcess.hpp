#pragma once
#include "../../../domain/logger/include/Logger.hpp"
#include "../../../domain/process/include/Process.hpp"
#include "../../../domain/process/include/ProcessorAffinity.hpp"
#include "../../../domain/util/include/FtqUtil.hpp"
#include "ProcessFactory.hpp"
#include "WorkerProcess.hpp"
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <string>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <vector>

#define WORKER_PROCESS_SHARED_MEMORY_KEY 1000

using namespace ftq_domain;

namespace ftq_driver {

class MasterProcess : public ftq_domain::Process {

  private:
	typedef struct SharedWorkerProcessMemorySegment {
		pthread_mutex_t socketMutexLock;
		int socketFileDescriptor;

	} SharedWorkerProcessMemorySegment;

	SharedWorkerProcessMemorySegment *workerProcessSharedMemory;
	int shmid;
	ftq_domain::uint8 cpuCount;
	std::vector<WorkerProcess> workerProcesses;
	pthread_mutexattr_t attr;
	ProcessFactory *processFactory;

	void createSharedMemorySegment() {

		shmid = shmget((key_t)WORKER_PROCESS_SHARED_MEMORY_KEY,
					   sizeof(SharedWorkerProcessMemorySegment), 0666 | IPC_CREAT);

		if (shmid == -1) {
			Logger::logError(ftq_domain::FTQ_LOG_ERR, "shmget failed.");
			exit(EXIT_FAILURE);
		}

		workerProcessSharedMemory = (SharedWorkerProcessMemorySegment *)shmat(shmid, (void *)0, 0);

		if (workerProcessSharedMemory == (void *)-1) {
			Logger::logError(ftq_domain::FTQ_LOG_ERR, "shmat failed.");
			exit(EXIT_FAILURE);
		}
	}

	void createSocketMutex() {

		pthread_mutexattr_init(&attr);
		pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

		if (pthread_mutex_init(&(workerProcessSharedMemory->socketMutexLock), &attr) != 0) {
			ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_ERR,
										 "Failed to create socket mutex lock!\n");

			exit(EXIT_FAILURE);
		}
	}
	/**
	 * createProcess creates a process object. A process object
	 * is an object representation of a currently running
	 * process
	 *
	 *
	 * @param processName The name of the process
	 * @param processType The type of process to be created i.e
	 * WORKER_PROCESS
	 * @param cpuId The cpu id the process is to be run on if
	 * process affinity is available on OS
	 * @return a pointer to the created process
	 */
	ftq_domain::Process *createProcess(std::string processName, ftq_domain::ProcessType processType,
									   ftq_domain::uint8 cpuId) {
		switch (processType) {
			{
			case ftq_domain::ProcessType::WORKER_PROCESS: {
				// TODO USE a factory
				WorkerProcess *workerProcess = processFactory->createWorkerProcess(
					processName, cpuId, &workerProcessSharedMemory->socketMutexLock);
				if (workerProcess != NULL) {
					addWorkerProcess(*workerProcess);
				}
				return workerProcess;
			}
			default:
				ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_WARN,
											 "Unknown Process Type: " +
												 std::to_string(processType));
				return NULL;
			}
		}
	}

	ftq_domain::Process *spawnProcess(std::string processName, ftq_domain::ProcessType processType,
									  ftq_domain::uint8 cpuId) {
		ftq_domain::Process *process = NULL;
		ftq_domain::ftq_pid_t pid = fork();

		if (pid == 0) {
			process = createProcess(processName, processType, cpuId);

			if (process == NULL) {
				// todo: log type of process and it's name too
				ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_ERR, "Failed to create process");
				exit(0); // exit the current process
			} else {
				ftq_domain::ProcessorAffinity::setProcessAffinity(process);
			}

		} else if (pid == -1) { // todo: log type of process and it's name too
			ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_ERR, "Failed to spawn process");
		}
		return process;
	}

	void startWorkerProcesses(ftq_domain::uint8 n) {
		Logger::logInfo("Master process starting " + std::to_string(n) + " worker processes");

		for (ftq_domain::uint8 i = 0; i < n; i++) {

			Process *process = spawnProcess("Worker process " + std::to_string(i),
											ftq_domain::ProcessType::WORKER_PROCESS, i);

			if (process != NULL) { // not the parent process
				process->run();
			}
		}
	}

	void addWorkerProcess(WorkerProcess WorkerProcess) { workerProcesses.push_back(WorkerProcess); }

  public:
	~MasterProcess() {
		if (shmdt(workerProcessSharedMemory) == -1) {
			Logger::logError(FTQ_LOG_ERR, "Failed to detached from worker process shared memory");
			exit(EXIT_FAILURE);
		}
		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			Logger::logError(FTQ_LOG_ERR, "Failed to delete worker process shared memory");
			exit(EXIT_FAILURE);
		}
	}
	MasterProcess(ProcessFactory *processFactory)
		: ftq_domain::Process("Master Process", ftq_domain::ProcessType::MASTER_PROCESS, getpid()) {

		this->cpuCount = sysconf(_SC_NPROCESSORS_CONF);
		this->processFactory = processFactory;

		createSharedMemorySegment();
		createSocketMutex();
	}

	ftq_domain::uint8 getCpuCount();

	void run() override;
}; // namespace ftq_driver

} // namespace ftq_driver