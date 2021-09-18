#pragma once

#include "../../../domain/util/include/FtqUtil.hpp"
#include "../../../domain/process/include/Process.hpp"
#include <string>


namespace ftq_driver {

    class WorkerProcess : public ftq_domain::Process {
            
        public:
            WorkerProcess(std::string processName, ftq_domain::ftq_pid_t pid, ftq_domain::uint8 cpuId) : 
            ftq_domain::Process(processName, ftq_domain::ProcessType::WORKER_PROCESS, pid, cpuId) {
                
            }

            void run() override;


            bool operator==(const WorkerProcess process){
                return process.pid == this->pid &&
                        process.processName == this->processName &&
                        process.processType == this->processType &&
                        process.cpuSet == this->cpuSet;
             
            }

             bool operator!=(const WorkerProcess process){
                return !(*this == process); 
             
            }

    };

};