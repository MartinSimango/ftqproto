#include "ProcessorAffinity.hpp"
#include "Process.hpp"
#include "Logger.hpp"
#include <string>

using namespace ftq;


void ProcessorAffinity::setProcessAffinity(Process* process) {

    #ifdef linux
    {
        std::vector<uint8> cpuIds = process->getProcessCpuSet();
        ftq_cpu_set_t cpuSet;

        CPU_ZERO(&cpuSet);
        for (uint8 i = 0; i < cpuIds.size(); i++) {
            CPU_SET(cpuIds.at(i), &cpuSet);
        }
        
        if(sched_setaffinity(0, sizeof(cpuSet), &cpuSet) == 0) {
            
            Logger::logInfo("Process affinity set for process:" + process->getProcessName() + "("  + std::to_string(process->getProcessPid()) + ")");
        } else {
            Logger::logError(FTQ_LOG_ERR, "Failed to set process affinity for process");
        // todo log error
        }

    }
    #else
        Logger::logInfo("Can not set process affinity for process: '"+ process->getProcessName() + "'");
    #endif
    
}





