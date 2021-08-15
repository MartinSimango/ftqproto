#pragma once
#include <string>
#include "FtqUtil.hpp"



enum FTQ_LOG_LEVEL {
    FTQ_LOG_ERR,
    FTQ_LOG_WARN,
    FTQ_LOG_NOTICE,
};


class Logger {

    public:

    void static logDebug(std::string fmt, ...);

    void static logError(FTQ_LOG_LEVEL level, std::string message);

    void static logInfo(std::string message);

};