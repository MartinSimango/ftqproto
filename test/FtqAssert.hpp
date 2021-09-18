#pragma once
#include "TestFailedException.hpp"
#include "../src/domain/util/include/FTQObject.hpp"
#include <sstream>

using namespace ftq_domain;

namespace ftq_test {

class FtqAssert {

    public:

    template<typename T>
    static void assertEqualTo(T a, T b) {

        std::stringstream reason;
        if (a != b) {
            reason << a << " does not equal " << b << std::endl;
            throw new TestFailedException(reason.str());
        }
    }

};

}


