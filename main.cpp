#include "usecase/process/MasterProcessImpl.hpp"

using namespace ftq;

int main(int argc, char * argv[]) {
    MasterProcess *masterProcess = new MasterProcessImpl();

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