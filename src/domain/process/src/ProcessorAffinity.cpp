#include "../../process/include/ProcessorAffinity.hpp"
#include "../../logger/include/Logger.hpp"
#include <string>

using namespace ftq_domain;

void ProcessorAffinity::setProcessAffinity(Process *process) {

#ifdef __linux__
	{
		std::vector<uint8> cpuIds = process->getProcessCpuSet();
		ftq_cpu_set_t cpuSet;

		CPU_ZERO(&cpuSet);
		for (uint8 i = 0; i < cpuIds.size(); i++) {
			CPU_SET(cpuIds.at(i), &cpuSet);
		}

		if (sched_setaffinity(0, sizeof(cpuSet), &cpuSet) == 0) {

			Logger::logInfo("Process affinity set for " + process->toString());
		} else {
			Logger::logError(FTQ_LOG_ERR,
							 "Failed to set process affinity for " + process->toString());
			// todo log error
		}
	}
#else
	Logger::logError(FTQ_LOG_NOTICE, "Can not set process affinity for: " + process->toString());
#endif
}

std::vector<uint8> ProcessorAffinity::getProcessAffinity(Process *process) {
	return process->getProcessCpuSet();
}
