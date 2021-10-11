#pragma once
#include "../src/domain/util/include/FTQObject.hpp"
#include "TestFailedException.hpp"
#include <sstream>

using namespace ftq_domain;

namespace ftq_test {

class FtqAssert {

public:
  template <typename T> static void assertEqualTo(T a, T b) {

    std::stringstream reason;
    if (a != b) {
      reason << "\nExpected: " << b << "\nGot: " << a << std::endl;
      throw new TestFailedException(reason.str());
    }
  }

  static void assertEqualTo(bool a, bool b) {

    std::stringstream reason;
    std::string a_value = (a == true) ? "true" : "false";
    std::string b_value = (b == true) ? "true" : "false";
    if (a != b) {

      reason << "\nExpected: " << b_value << "\nGot: " << a_value << std::endl;
      throw new TestFailedException(reason.str());
    }
  }
};

} // namespace ftq_test
