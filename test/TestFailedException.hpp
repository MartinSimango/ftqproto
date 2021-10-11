
#pragma once
#include <exception>
#include <iostream>
#include <string.h>

namespace ftq_test {

class TestFailedException final : public std::exception {
private:
  std::string reason;

public:
  TestFailedException(std::string reason) : std::exception(), reason(reason) {}

  const char *what() const throw() override { return reason.c_str(); }
  virtual std::string getReason() { return reason; }
};

} // namespace ftq_test