#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Test.hpp"
#include "FtqAssert.hpp"

namespace ftq_test {



class FtqTest {

    private:
        std::string testName;
        std::vector<Test*> tests;

    protected:

        void registerTest(std::string name, Test::Type test) {
            tests.push_back(new Test(name, test));
        }
    
    public:

        FtqTest(std::string testName): testName(testName) {
        }

        virtual ~FtqTest(){
             while (!tests.empty())
            {
                delete tests.back();
                tests.pop_back();
            }
        }

        virtual void run() {
            for (Test *test : tests) {
                   test->run();
            }
        }
        
       
        virtual void printResult() {

            for (Test *test: tests) {
                test->printResult();
            }
        }

        std::string getTestName() {
            return testName;
        }

};



}