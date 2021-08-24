#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Test.hpp"
#include "FtqAssert.hpp"

namespace ftq {



class FtqTest {

    private:
        std::string testName;
        std::vector<Test*> tests;

         //should only be albe to register test from current class
            //  using Type = RetVal(Object::*)(Args...);
    protected:

        void registerTest(std::string name, Test::Type test) {
            tests.push_back(new Test(name, test));
        }
    
    public:

        FtqTest(std::string testName): testName(testName) {}

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

        virtual void setupTests() = 0;

};



}