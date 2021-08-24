
#pragma once
#include <exception>
#include <string.h>
#include <iostream>

namespace ftq
{

    class TestFailedException final : public std::exception {
        private:
            std::string reason;
        public:

            TestFailedException(std::string reason): std::exception(), reason(reason) {}

            const char * what() const throw() override {
                return reason.c_str();   
            }
            virtual std::string getReason() {
                return reason;
            }
        
    };

}