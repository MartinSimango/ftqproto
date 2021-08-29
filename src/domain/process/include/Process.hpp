#pragma once

#include "../../util/include/FtqUtil.hpp"
#include "../../logger/include/Logger.hpp"
#include <unistd.h>
#include <string>
#include <vector>

namespace ftq_domain {

#define ftq_getpid getpid;

typedef pid_t ftq_pid_t;

enum ProcessType {
    WORKER_PROCESS,
    MASTER_PROCESS
};

class Process {

    private:
        ProcessType processType;
        std::string processName;
        ftq_pid_t pid;
        std::vector<uint8> cpuSet;
        
    public:

         Process(std::string processName, ProcessType processType, ftq_pid_t pid)  {
            this->processName = processName;
            this->processType = processType;
            this->pid = pid;
        }

         Process(std::string processName, ProcessType processType, ftq_pid_t pid, uint8 cpuId)  {
            this->processName = processName;
            this->processType = processType;
            this->pid = pid;
            cpuSet.push_back(cpuId);
        }

        Process(std::string processName, ProcessType processType, ftq_pid_t pid, std::vector<uint8> cpuSet)  {
            this->processName = processName;
            this->processType = processType;
            this->pid = pid;
            this->cpuSet = cpuSet;
        }
        
        virtual void run() = 0;
        

        ftq_pid_t getProcessPid() {
            return pid;
        }

        std::string getProcessName() {
            return processName;
        }

        ProcessType getProcessType() {
            return processType;
        }

        std::vector<uint8> getProcessCpuSet() {
            return cpuSet;
        }
        
        virtual std::string toString() {
           return processName + " (PID: "  + std::to_string(pid) + ")";
        }
};

}