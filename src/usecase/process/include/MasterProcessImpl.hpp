#pragma once

#include "MasterProcess.hpp"
#include <iostream>
#include "../../../domain/process/include/ProcessorAffinity.hpp"
#include "../../../domain/logger/include/Logger.hpp"


namespace ftq_usecase {

    class MasterProcessImpl : public MasterProcess {

        private:
            WorkerProcess * createWorkerProcess(std::string name, ftq_domain::uint8 cpuId) {
                WorkerProcess * process = new WorkerProcess(name, getpid(), cpuId);
                return process;
            }

            
            ftq_domain::Process* createProcess(std::string processName, ftq_domain::ProcessType processType, ftq_domain::uint8 cpuId) {
                switch (processType) {
                    {
                    case ftq_domain::ProcessType::WORKER_PROCESS: {
                        WorkerProcess * workerProcess = createWorkerProcess(processName, cpuId);
                        addWorkerProcess(*workerProcess);
                        return workerProcess;     
                    }               
                    default:
                        return NULL;
                    }
                }
            }


            void startWorkerProcesses(ftq_domain::uint8 n) override {
                ftq_domain::Logger::logInfo("Master process starting " + std::to_string(n) + " worker processes");
                for (ftq_domain::uint8 i = 0; i < n ; i++) {
                    Process * process = spawnProcess("Worker process " + std::to_string(i), ftq_domain::ProcessType::WORKER_PROCESS, i);
                    if (process != NULL) { // not that parent process
                        process->run(); 
                    }                  
                }
            }

            ftq_domain::Process* spawnProcess(std::string processName, ftq_domain::ProcessType processType, ftq_domain::uint8 cpuId) override {
                ftq_domain::Process* process = NULL;

                ftq_domain::ftq_pid_t pid = fork();

                switch (pid)
                {
                    case -1:
                        return NULL; 
                    case 0: {
                        process = createProcess(processName, processType, cpuId);
                        ftq_domain::ProcessorAffinity::setProcessAffinity(process);
        
                    }
                    break;
                    default:
                        return NULL; // parent process
                }
          
                // todo: use logger
                return process;
                            
            }

        public:

            MasterProcessImpl(): MasterProcess() {

            }

            void run() override;

    };

};