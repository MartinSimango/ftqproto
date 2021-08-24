#pragma once

#include "FtqTest.hpp"


namespace ftq {
    
class DemoTest : public FtqTest {

    public:

    DemoTest(std::string testName) : FtqTest(testName) {
        setupTests();
    }

    void setupTests() override {
        registerTest("does1equal1", does1equal1);
        registerTest("does1equal2", does1equal2);

    }

    // TESTS

    static void does1equal1() {
        FtqAssert::assertEqualTo(1,1);
    }

    static void does1equal2() {
        FtqAssert::assertEqualTo(1,2);

    }

};


}