#pragma once

#include "../../logger/include/Logger.hpp"
#include "../../util/include/FTQObject.hpp"
#include "../../util/include/FtqUtil.hpp"
#include <string>
#include <unistd.h>
#include <vector>

namespace ftq_domain {

#define ftq_getpid getpid;

typedef pid_t ftq_pid_t;

enum ProcessType { WORKER_PROCESS, MASTER_PROCESS };

class Process : public FTQObject {

protected:
  ProcessType processType;
  std::string processName;
  ftq_pid_t pid;
  std::vector<uint8> cpuSet;

public:
  Process(std::string processName, ProcessType processType, ftq_pid_t pid) {
    this->processName = processName;
    this->processType = processType;
    this->pid = pid;
  }

  Process(std::string processName, ProcessType processType, ftq_pid_t pid,
          uint8 cpuId) {
    this->processName = processName;
    this->processType = processType;
    this->pid = pid;
    cpuSet.push_back(cpuId);
  }

  Process(std::string processName, ProcessType processType, ftq_pid_t pid,
          std::vector<uint8> cpuSet) {
    this->processName = processName;
    this->processType = processType;
    this->pid = pid;
    this->cpuSet = cpuSet;
  }

  virtual void run() = 0;

  ftq_pid_t getProcessPid() { return pid; }

  std::string getProcessName() { return processName; }

  ProcessType getProcessType() { return processType; }

  std::vector<uint8> getProcessCpuSet() { return cpuSet; }

  virtual std::string toString() override {
    return processName + " (PID: " + std::to_string(pid) + ")";
  }

  bool equals(FTQObject *ftqObject) override {
    Process *process = dynamic_cast<Process *>(ftqObject);
    return process->pid == this->pid &&
           process->processName == this->processName &&
           process->processType == this->processType &&
           process->cpuSet == this->cpuSet;
  }

  friend std::ostream &operator<<(std::ostream &os, const Process &process) {
    std::string cpuSetString = "[";
    uint8 i;
    for (i = 0; i < process.cpuSet.size(); i++) {
      if (i == process.cpuSet.size() - 1) {
        cpuSetString += std::to_string(process.cpuSet.at(i));
        break;
      }
      cpuSetString += std::to_string(process.cpuSet.at(i)) + ",";
    }
    cpuSetString += "]";

    return (os << "{Process name: " << process.processName << ", PID: "
               << process.pid << ", Process Type: " << process.processType
               << ", Cpu set: " << cpuSetString << "}");
  }
};

} // namespace ftq_domain