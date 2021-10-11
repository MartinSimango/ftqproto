#pragma once
#include "FtqTest.hpp"

#define ADD_TEST_CLASS(class) FtqTests::addTest(new class());

namespace ftq_test {

class FtqTests {
public:
  static std::vector<FtqTest *> allTests;

  static void addTest(FtqTest *test) { allTests.push_back(test); }

  static void removeAllTests() {

    while (!allTests.empty()) {
      delete allTests.back();
      allTests.pop_back();
    }
  }

  static bool runAllTests() {
    for (FtqTest *test : allTests) {
      test->run();
    }

    return true;
  }

  static void printResults() {
    // todo: check if tests have run and print number of test failed and passed
    int passed = 0;
    int failed = 0;
    for (FtqTest *test : allTests) {
      std::cout << "--- " << test->getTestName() << " ---\n"
                << std::endl; // todo use logger
      test->printResult();
      passed += test->getPassedTests().size();
      failed += test->getFailedTests().size();
    }

    std::cout << "--- Summary for All Tests: ---" << std::endl;
    if (passed > 0) {
      std::cout << passed << " test(s) passed" << std::endl;
    }
    if (failed > 0) {
      std::cout << failed << " test(s) failed" << std::endl;
    }
    std::cout << std::endl;
  }
};

std::vector<FtqTest *> FtqTests::allTests;

} // namespace ftq_test