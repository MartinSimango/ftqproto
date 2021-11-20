#pragma once

#include "../../util/include/FtqUtil.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

namespace ftq_domain {

enum FTQ_LOG_LEVEL {
  FTQ_LOG_ERR,
  FTQ_LOG_WARN,
  FTQ_LOG_NOTICE,
};

class Logger {

private:
  std::string static getCurrentTime() {
    std::time_t currentTime =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string currentTimeAsString = std::ctime(&currentTime);
    currentTimeAsString.erase(std::remove(currentTimeAsString.begin(),
                                          currentTimeAsString.end(), '\n'),
                              currentTimeAsString.end());
    return currentTimeAsString;
  }

  std::string static getLogLevel(FTQ_LOG_LEVEL level) {
    switch (level) {
    case FTQ_LOG_ERR:
      return "ERR";
    case FTQ_LOG_NOTICE:
      return "NOTICE";
    case FTQ_LOG_WARN:
      return "WARN";
    }
    return "UNDEFINED";
  }

public:
  void static logDebug(std::string fmt, ...);

  void static logError(FTQ_LOG_LEVEL level, std::string message);

  void static logInfo(std::string message);
};

} // namespace ftq_domain