#include "FtqTests.hpp"
#include "DemoTest.hpp"
#include "unit/process/ProcessFactoryTests.cpp"
#include "mocking/MockFunctions.hpp"
#include <string>
using namespace ftq_test;

void addTests() {
    FtqTests::addTest(new DemoTest("Demo Test 1"));
    FtqTests::addTest(new ProcessFactoryTests());
    // FtqTests::addTest(new DemoTest("Demo Test 2"));


}


MOCK_INTERFACE(SomeInterface,
    MOCK_2(SomeInterface, foo)
    MOCK_1(SomeInterface, boo)
)


int main() {

    // addTests();
    // FtqTests::runAllTests();
    // FtqTests::printResults();
 

    Mock<SomeInterfaceMock> mock;
    

    SomeInterface &i = mock.get();


    expectThat(mock, foo).with(2,"hello").willReturn(10);


    int value = i.foo(23, "hello");
    std::cout << "Val: " << value << std::endl;

    bool verif = Verify(mock, foo).wasCalledWith(2,"hell");

    if(verif) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

}

// MOCKM(SomeInterface, foo)
// FUNC_RETURN_TYPE(&SomeInterface::foo) foo(FUNC_ARGS_N(&SomeInterface::foo, 1))
