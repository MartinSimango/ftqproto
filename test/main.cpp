#include "FtqTests.hpp"
#include "DemoTest.hpp"
#include "unit/process/ProcessFactoryTests.cpp"
#include "mocking/Mocker.hpp"
#include <string>
using namespace ftq_test;

void addTests() {
    FtqTests::addTest(new DemoTest("Demo Test 1"));
    FtqTests::addTest(new ProcessFactoryTests());
    // FtqTests::addTest(new DemoTest("Demo Test 2"));


}

void callMock(SomeInterface *a) {
    a->foo(2,2);
}




int main() {
    // addTests();
    // FtqTests::runAllTests();
    // FtqTests::printResults();

    Mock<SomeInterfaceMock> mock;
    SomeInterface &i = mock.get();

    expectThat(mock, foo).with(2,2).willReturn(10);


    int value = i.foo(2,2);

    bool verif = Verify(mock, foo).wasCalledWith(2,2);

    if(verif) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

}