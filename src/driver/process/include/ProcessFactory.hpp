#pragma once

#include "../include/WorkerProcess.hpp"


namespace ftq_driver {

    class ProcessFactory {

        public:

        ProcessFactory(){}
        /**
         * createWorkerProcess creates a worker process object. A worker process object is an object representation of a 
         * currently running worker process.
         *
         * @param processName The name of the process
         * @param cpuId The cpu id the process is to be run on if process affinity is available on OS
         * @return a pointer to the created worker process
         */
        virtual WorkerProcess * createWorkerProcess(std::string name, ftq_domain::uint8 cpuId);

    };

}