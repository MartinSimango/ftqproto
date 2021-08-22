#pragma once
#include "../../domain/FtqUtil.hpp"
#include "../../domain/Process.hpp"
#include <string>


namespace ftq {

    class WorkerProcess : public Process {
            
        public:
            WorkerProcess(std::string processName, ftq_pid_t pid, uint8 cpuId) : Process(processName, WORKER_PROCESS, cpuId) {}

            void run() override;

    };

};
// wwangambazi@gmail.com 