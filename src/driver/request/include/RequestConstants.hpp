#pragma once

#define KILOBYTE 1024
#define MEGABYTE 1024*1024
#define MAX_BUFFER_SIZE MEGABYTE

namespace ftq_driver {
    
    namespace RequestType {
        enum Type {
            UNKNOWN,
            CREATE,
            GET,
            READ,
            WRITE
        };

    }
}
