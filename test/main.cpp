#include "FtqTests.hpp"
#include "DemoTest.hpp"

using namespace ftq;

void addTests() {
    FtqTests::addTest(new DemoTest("Demo Test 1"));
    // FtqTests::addTest(new DemoTest("Demo Test 2"));


}

int main() {
    addTests();
    FtqTests::runAllTests();
    FtqTests::printResults();

    
    FtqTests::runAllTests();
    FtqTests::printResults();

    // FtqTest::

}
