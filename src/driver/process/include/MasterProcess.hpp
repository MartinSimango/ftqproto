#pragma once
#include "../../../domain/util/include/FtqUtil.hpp"
#include "../../../domain/process/include/Process.hpp"
#include "../../../domain/process/include/ProcessorAffinity.hpp"
#include "WorkerProcess.hpp"
#include "ProcessFactory.hpp"
#include <unistd.h>
#include <vector>


namespace ftq_driver {


class MasterProcess : public ftq_domain::Process {

    private:
        ftq_domain::uint8 cpuCount;
        std::vector<WorkerProcess> workerProcesses;
        ProcessFactory *processFactory;

       /**
         * createProcess creates a process object. A process object is an object representation of a currently running process
         * 
         *
         * @param processName The name of the process
         * @param processType The type of process to be created i.e WORKER_PROCESS
         * @param cpuId The cpu id the process is to be run on if process affinity is available on OS
         * @return a pointer to the created process
         */
        ftq_domain::Process* createProcess(std::string processName, ftq_domain::ProcessType processType, ftq_domain::uint8 cpuId) {
            switch (processType) {
                {
                case ftq_domain::ProcessType::WORKER_PROCESS: {
                    // TODO USE a factory
                    WorkerProcess * workerProcess = processFactory->createWorkerProcess(processName, cpuId);
                    if (workerProcess != NULL){
                        addWorkerProcess(*workerProcess);
                    }
                    return workerProcess;     
                }               
                default:
                    ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_WARN, "Unknown Process Type: " + std::to_string(processType));
                    return NULL;
                }
            }
        }

        ftq_domain::Process* spawnProcess(std::string processName, ftq_domain::ProcessType processType, ftq_domain::uint8 cpuId)  {
            ftq_domain::Process* process = NULL;
            ftq_domain::ftq_pid_t pid = fork();

            if (pid == 0) {
                process = createProcess(processName, processType, cpuId);

                if (process == NULL) {
                    // todo: log type of process and it's name too
                    ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_ERR, "Failed to create process ");
                    exit(0); //exit the current process
                } else {
                    ftq_domain::ProcessorAffinity::setProcessAffinity(process);
                }

            } else if (pid == -1) {
                // todo: log type of process and it's name too
                ftq_domain::Logger::logError(ftq_domain::FTQ_LOG_ERR, "Failed to spawn process ");
            }
            return process;                   
        }

        void startWorkerProcesses(ftq_domain::uint8 n) {
            ftq_domain::Logger::logInfo("Master process starting " + std::to_string(n) + " worker processes");

            for (ftq_domain::uint8 i = 0; i < n ; i++) {

                Process * process = spawnProcess("Worker process " + std::to_string(i), ftq_domain::ProcessType::WORKER_PROCESS, i);
                if (process != NULL) { // not that parent process
                    process->run(); 
                }                  
            }
        }

        void addWorkerProcess(WorkerProcess WorkerProcess) {
            workerProcesses.push_back(WorkerProcess);
        }

    public:

        MasterProcess(ProcessFactory * processFactory) : ftq_domain::Process("Master Process", ftq_domain::ProcessType::MASTER_PROCESS, getpid()) {
            cpuCount = sysconf(_SC_NPROCESSORS_CONF);
            this->processFactory = processFactory;
        }
    
        ftq_domain::uint8 getCpuCount();

        void run() override;

};

}