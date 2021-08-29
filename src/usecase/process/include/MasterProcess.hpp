#pragma once
#include "../../../domain/util/include/FtqUtil.hpp"
#include "../../../domain/process/include/Process.hpp"
#include "WorkerProcess.hpp"
#include <unistd.h>
#include <vector>


namespace ftq_usecase {


class MasterProcess : public ftq_domain::Process {

    private:
        ftq_domain::uint8 cpuCount;
        std::vector<WorkerProcess> workerProcesses;

    protected:
        virtual void startWorkerProcesses(ftq_domain::uint8 n) = 0;

        virtual Process* spawnProcess(std::string processName, ftq_domain::ProcessType processType, ftq_domain::uint8 cpuId) = 0;

        void addWorkerProcess(WorkerProcess WorkerProcess) {
            workerProcesses.push_back(WorkerProcess);
        }

    public:

        MasterProcess() : ftq_domain::Process("Master Process", ftq_domain::ProcessType::MASTER_PROCESS, getpid()) {
            cpuCount = sysconf(_SC_NPROCESSORS_CONF);
        }
    
        ftq_domain::uint8 getCpuCount() {
            return cpuCount;
        }



};

}