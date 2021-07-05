#pragma once


namespace frw {

    enum FileReadWriterStatus {
        OK,
        FILE_NOT_FOUND,
        NO_WRITE_PERMISSIONS,
        NO_READ_PERMISSIONS,
        FAILED_TO_CREATE_FILE,
        FAILED_TO_CREATE_DIRECTORY,
        OPERATION_NOT_PERMITTED
    };

}


