#pragma once
#include <iostream>
#include <exception> 

namespace ftq_domain
{

    class Exception : public std::exception {
        private:
            std::string errorMessage;
        public:
            Exception(): std::exception(), errorMessage(""){}

            
            Exception(std::string errorMessage): std::exception(), errorMessage(errorMessage) {}

            
            virtual std::string getErrorMessage() {
                return errorMessage;
            }
        
    };

}