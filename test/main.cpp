#include "DemoTest.hpp"
#include "FtqTests.hpp"
#include "mocking/MockFunctions.hpp"
#include "unit/fileIO/FileIOTests.cpp"
#include "unit/process/ProcessFactoryTests.cpp"
#include <string>
using namespace ftq_test;

void addTests() {
  ADD_TEST_CLASS(ProcessFactoryTests);
  ADD_TEST_CLASS(FileIOTests);
}

int main() {

  addTests();
  FtqTests::runAllTests();
  FtqTests::printResults();
}
