#pragma once

#include <string>

namespace ResponseType {
    enum Type {
        HEADER = 100, //starts at 100 to not conflict with request types
        CREATE,
        GET,
        READ,
        WRITE,
        UNKNOWN
    };

}

namespace ResponseStatus {
    enum Type {
        UNKNOWN,
        OK,
        FILE_NOT_FOUND,
        NO_READ_PERMISSIONS,
        NO_WRITE_PERMISIONS,
    };
    
    static const std::string GetResponseName(Type status) {
        switch (status)
        {
        case OK:
            return "OK";
        case FILE_NOT_FOUND:
            return "FILE NOT FOUND";
        case NO_READ_PERMISSIONS:
            return "NO READ PERMISSIONS";
        case NO_WRITE_PERMISIONS:
            return "NO WRITE PERMISSIONS";
        default:
            return "UNKNOWN";
        }
    }
}
