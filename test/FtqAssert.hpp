#pragma once
#include "TestFailedException.hpp"

namespace ftq {

class FtqAssert {

    public:

    template<typename T>
    static void assertEqualTo(T a, T b) {
        if (a != b) {
            std::string reason = std::to_string(a) + " does not equal " + std::to_string(b);
            throw new TestFailedException(reason);
        }
     
    }


};

}


