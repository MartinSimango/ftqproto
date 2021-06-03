#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct CreateResponseStruct {
        char ** filenames;
        int * fileSizes;
        bool * isDirs;
        int numFiles;
} CreateResponseStruct;

void DestroyCreateResponse(void *cr);

CreateResponseStruct GetCreateResponse(void *cr);


#ifdef __cplusplus
}  // extern "C"
#endif
