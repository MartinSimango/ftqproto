#include "driver/process/include/MasterProcess.hpp"

using namespace ftq_driver;

int main(int argc, char * argv[]) {
    ProcessFactory * processFactory = new ProcessFactory();
    MasterProcess *masterProcess = new MasterProcess(processFactory);

    masterProcess->run();
    delete processFactory;
    delete masterProcess;

      // 1. start master process
    // 2. initlize socket and start listen for traffic
    // 3. initlize mutex for worker process to use
    // 3. start worker process and pass listening socket to each of them
    // 4. worker process should try obtain a mutex to see which process 


    // other implement code for logger
    // master process
    // ftq_start_master_process();
    // int nprocs_max = sysconf(_SC_NPROCESSORS_CONF);
    // ftq_process_t worker_processes[nprocs_max];

    // printf("In the master process\n");
    // ftq_start_worker_processes(nprocs_max);

}