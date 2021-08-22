#pragma once
#include "../../domain/FtqUtil.hpp"
#include "../../domain/Process.hpp"
#include "WorkerProcess.hpp"
#include <unistd.h>
#include <vector>

namespace ftq {


class MasterProcess : public Process {

    private:
        uint8 cpuCount;
        std::vector<WorkerProcess> workerProcesses;

    protected:
        virtual void startWorkerProcesses(uint8 n) = 0;

        virtual Process* spawnProcess(std::string processName, ProcessType processType, uint8 cpuId) = 0;

        void addWorkerProcess(WorkerProcess WorkerProcess) {
            workerProcesses.push_back(WorkerProcess);
        }

    public:

        MasterProcess() : Process("Master Process", MASTER_PROCESS, getpid()) {
            cpuCount = sysconf(_SC_NPROCESSORS_CONF);
        }
    
        uint8 getCpuCount() {
            return cpuCount;
        }



};

}