#include "../include/Logger.hpp"

using namespace ftq_domain;

void Logger::logError(FTQ_LOG_LEVEL level, std::string message) {
  std::string logLevel = Logger::getLogLevel(level);
  std::cout << "[" << Logger::getCurrentTime() << "] "
            << "[" << logLevel << "] " << message << std::endl;
}

void Logger::logInfo(std::string message) {
  std::cout << "[" << Logger::getCurrentTime() << "] " << message << std::endl;
}