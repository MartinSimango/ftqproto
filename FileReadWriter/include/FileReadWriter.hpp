#pragma once
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <ftqproto/FRWException.hpp>
#include <ftqproto/FileReadWriterConstants.hpp>
#include <ftqproto/ResponseConstants.hpp>



namespace frw {

    class FileReadWriter
    {
        
    private:
        char filename[MAX_FILEPATH_LENGTH];
        Mode::Type mode;
        bool opened;
        int fd, fileSize;
        
        inline void openFileForReading() {         
            if ( (this->fd = open(this->filename, O_RDONLY) ) < 0) 
                throw new FRWException(FAILED_TO_OPEN_FILE_FOR_READING, this->filename);   
            opened = true;    
    
        }

        inline void openFileForWriting() {
            if ( (this->fd = open(this->filename, O_WRONLY) ) < 0) 
                throw new FRWException(FAILED_TO_OPEN_FILE_FOR_WRITING, this->filename);
            opened = true;    
        }

        static inline ResponseStatus::Type checkFileForRead(const char * filename) {
                if (access(filename, F_OK) == 0) {
                    return access(filename, R_OK) == 0 ? ResponseStatus::OK : ResponseStatus::NO_READ_PERMISSIONS;
                }
                else {
                    return ResponseStatus::FILE_NOT_FOUND;
                }
            }    

        static inline ResponseStatus::Type checkFileForWrite(const char * filename) {
            if (access(filename, F_OK) == 0) {
                return access(filename, W_OK) == 0 ? ResponseStatus::OK : ResponseStatus::NO_WRITE_PERMISIONS;
            }
            return ResponseStatus::OK;
        }
                
        
    public:

        FileReadWriter(const char * filename, Mode::Type mode): mode(mode), opened(false){
            strncpy(this->filename, filename ,sizeof(this->filename));
        }

        ~FileReadWriter(){}

        // Open opens the file resource
        void Open();

        int WriteToFile(int offset, const char * data);

        int ReadFromFile(char *data, int offset, int numberOfBytesToRead);

        // Closes closes the file resource
        void Close();

        const char * GetFileName() const;

        int GetFileSize() const;

        int GetFileDescriptor() const;

        static ResponseStatus::Type CheckFile(const char * filename, Mode::Type mode);

        static bool CheckFileIsDirectory(const char * filename);

        static int GetFileSize(const char *filename);

        static void CreateFile(const char *filename, int fileSize, mode_t mode = 0666); //todo implement mode

        static void CreateDirectory(const char * dirname, mode_t mode = 0666); //todo implement mode

        static void RenameFile(std::string oldname, std::string newname);

        static bool DoesFileExist(std::string filePath);

    };


}