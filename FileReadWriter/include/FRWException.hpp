#pragma once
#include <cpperror/ErrorException.hpp>


static const char * FAILED_TO_RESIZE_FILE = "Failed to resize file.";
static const char * INVALID_FILE_SIZE = "A valid file size needs to be specified when creating a file.";
static const char * FAILED_TO_GET_FILE_SIZE = "Failed to get file size";


static const char * FAILED_TO_OPEN_FILE_FOR_WRITING = "Failed to open file for writing.";
static const char * FAILED_TO_OPEN_FILE_FOR_READING = "Failed to open file for reading.";
static const char * FAILED_TO_CREATE_FILE = "Failed to create file.";
static const char * FAILED_TO_CREATE_DIRECTORY = "Failed to create directory.";



static const char * FAILED_TO_CLOSE_FILE = "Failed to close file.";
static const char * FAILED_TO_OPEN_FILE_ALREADY_OPEN = "Failed to open file as file is already open.";

static const char * FAILED_TO_READ_FROM_FILE = "Failed to read from file.";
static const char * FAILED_TO_WRITE_TO_FILE = "Failed to write to file.";
static const char * FAILED_TO_WRITE_FILE_NOT_OPEN = "Cannot write to unopened file."; 
static const char * FAILED_TO_READ_FILE_NOT_OPEN = "Cannot read to unopened file.";
static const char * FAILED_TO_CLOSE_FILE_NOT_OPEN = "Cannot close unopened file.";
static const char * FAILED_TO_GET_FD_NOT_OPEN = "Cannot get file descriptor of closed or unopened file.";



class FRWException : public error::ErrorException {
    
    private:
	    const char* error;
        const char* filename;
    
    public:
        FRWException(const char *error, const char * filename) : error::ErrorException(), error(error), filename(filename){}
    	
        const char * what() const throw() override {
            return error;   
        }

        const char * getFilename() const {
            return filename;   
        }
        
        std::string getErrorMessage() override {
            return "[Error] " + std::string(strerror(errno)) + "\n[FRWException] Error: " + this->error + 
                    "\n[FRWException] File: " + this->filename;
        }
       
};
