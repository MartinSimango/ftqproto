#pragma once

#include <string>
#include <ostream>

namespace ftq_domain {

class FTQObject {
    public:
        virtual bool equals(FTQObject * ftqObject) {
            return this == ftqObject;
        }

        virtual std::string toString() {
            return "To string not implemented";
        }

};


}