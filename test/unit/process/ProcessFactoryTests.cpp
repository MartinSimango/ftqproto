// #pragma once

#include "../../FtqTest.hpp"
#include "../../../src/driver/process/include/ProcessFactory.hpp"

using namespace ftq_driver;

namespace ftq_test {

// todo make test classes Singletons
class ProcessFactoryTests : public FtqTest {

    private:
    static ProcessFactory * processFactory;

    static void setUp() {
        delete processFactory;
        processFactory = new ProcessFactory();
    }

    static void destroy() {
        delete processFactory;
        processFactory = NULL;
    }

    public:

    ProcessFactoryTests() : FtqTest("ProcessFactoryTests") {
        setupTests();
    }

    ~ProcessFactoryTests() {}
    

    void setupTests() {
        setUp();
        registerTest("testCreateWorkerProcess_shouldAssertToTrue", testCreateWorkerProcess_shouldAssertToTrue);

    }


    // TESTS

    static void testCreateWorkerProcess_shouldAssertToTrue() {
        WorkerProcess expectedWorkerProcess("worker", getpid(), 1);

        // expectThat(processFactory, createWorkerProcess).with("worker",0,1).willReturn(..)

        WorkerProcess *actualWorkerProcessPointer = processFactory->createWorkerProcess("worker", 0);
        WorkerProcess actualWorkerProcess = *actualWorkerProcessPointer;
        delete actualWorkerProcessPointer;
        
        
        FtqAssert::assertEqualTo(expectedWorkerProcess, actualWorkerProcess);
    }

};

ProcessFactory* ProcessFactoryTests::processFactory = NULL;


}