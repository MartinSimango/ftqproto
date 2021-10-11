#pragma once

#include "TestFailedException.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace ftq_test {

class Test {

public:
  using Type = void (*)();

private:
  std::string name;
  std::string *reason = NULL;
  Type test;
  bool pass = false;

public:
  Test(std::string testName, Type test) {
    this->name = testName;
    this->test = test;
  }

  virtual ~Test() {
    delete reason;
    reason = NULL;
  }

  void run() {
    try {
      test();
      this->pass = true;
    } catch (TestFailedException *exception) {
      delete reason;

      reason = new std::string(exception->getReason());
      delete exception;
    }
  }

  bool didPass() { return pass; }

  void printResult() {
    if (pass) {
      std::cout << "Test '" << name << "' passed\n" << std::endl;
    } else {
      std::cout << "Test '" << name << "' failed: " << *reason << std::endl;
    }
  }
};
} // namespace ftq_test
