#pragma once

#include "FtqAssert.hpp"
#include "Test.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define REGISTER_TEST(testName) registerTest(#testName, testName)

namespace ftq_test {

class FtqTest {

private:
  std::string testName;
  std::vector<Test *> tests;
  std::vector<Test *> passedTests;
  std::vector<Test *> failedTests;

protected:
  void registerTest(std::string name, Test::Type test) {
    tests.push_back(new Test(name, test));
  }

public:
  FtqTest(std::string testName) : testName(testName) {}

  virtual ~FtqTest() {
    while (!tests.empty()) {
      delete tests.back();
      tests.pop_back();
    }
  }

  virtual void run() {
    for (Test *test : tests) {
      test->run();
      if (test->didPass()) {
        passedTests.push_back(test);
      } else {
        failedTests.push_back(test);
      }
    }
  }

  virtual void printResult() {

    for (Test *test : tests) {
      test->printResult();
    }
    std::cout << "[Summary for '" << testName << "']:" << std::endl;
    if (passedTests.size() > 0) {
      std::cout << passedTests.size() << " test(s) passed" << std::endl;
    }
    if (failedTests.size() > 0) {
      std::cout << failedTests.size() << " test(s) failed" << std::endl;
    }
    std::cout << std::endl;
  }

  std::vector<Test *> getPassedTests() { return passedTests; }

  std::vector<Test *> getFailedTests() { return failedTests; }

  std::string getTestName() { return testName; }
};

} // namespace ftq_test
