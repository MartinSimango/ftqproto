#pragma once

#include "MasterProcess.hpp"
#include <iostream>
#include "../../domain/ProcessorAffinity.hpp"

namespace ftq {

    class MasterProcessImpl : public MasterProcess {

        private:
            WorkerProcess * createWorkerProcess(std::string name, uint8 cpuId) {
                WorkerProcess * process = new WorkerProcess(name, getpid(), cpuId);
                return process;
            }

            
            Process* createProcess(std::string processName, ProcessType processType, uint8 cpuId) {
                switch (processType) {
                    {
                    case WORKER_PROCESS: {
                        WorkerProcess * workerProcess = createWorkerProcess(processName, cpuId);
                        addWorkerProcess(*workerProcess);
                        return workerProcess;     
                    }               
                    default:
                        return NULL;
                    }
                }
            }


            void startWorkerProcesses(uint8 n) override {
                
                for (uint8 i = 0; i < n ; i++) {
                    Process * process = spawnProcess("Worker process " + i, WORKER_PROCESS, i);
                    process->run();
                }
            }

            Process* spawnProcess(std::string processName, ProcessType processType, uint8 cpuId) override {
                Process * process = NULL;

                ftq_pid_t pid = fork();
                
                switch (pid)
                {
                    case -1:
                        return NULL; 
                    case 0: {
                        process = createProcess(processName, processType, cpuId);
                        ProcessorAffinity::setProcessAffinity(process);
                    }
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