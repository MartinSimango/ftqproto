#pragma once
#include "FtqTest.hpp"

namespace ftq {

    class FtqTests {
        public:

        static std::vector<FtqTest*> allTests;

        static void addTest(FtqTest * test) {
            allTests.push_back(test);
        }

        static void removeAllTests() {
            
            while (!allTests.empty())
            {
                delete allTests.back();
                allTests.pop_back();
            }
            
        }

        static bool runAllTests() {
            for (FtqTest* test: allTests) {
                test->run();
            }

            return true; 
        }
 
        static void printResults() {
            //todo: check if tests have run and print number of test failed and passed
            for(FtqTest* test: allTests) {
                std::cout << test->getTestName() << ":" <<std::endl; //todo use logger
                test->printResult();
            }

        }
    };
    
std::vector<FtqTest*> FtqTests::allTests;

}