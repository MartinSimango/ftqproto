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
                 switch (processType)
                    {
                    case WORKER_PROCESS:
                        WorkerProcess * workerProcess = createWorkerProcess(processName, cpuId);
                        addWorkerProcess(*workerProcess);
                        process = workerProcess;
                        break;
                    
                    default:
                        return NULL;
                    }
                    ProccesorAffinity::setProcessAffinity(cpuId); 
                }
               
                   
                
                default:
                    return NULL;
                }

                // todo: use logger
                std::cout << processName << " started" << std::endl; 
                return process;
                            
            }

        public:

            MasterProcessImpl(): MasterProcess() {

            }

            void run() override;

    };

};