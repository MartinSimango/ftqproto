#include <ftqproto/FileReadWriter.hpp>
#include <stdio.h>

using namespace frw;

void FileReadWriter::Open(){
    if(opened){
        throw new FRWException(FAILED_TO_OPEN_FILE_ALREADY_OPEN, filename);
    }
    (mode == Mode::READ) ? openFileForReading() : openFileForWriting();
    opened = true;
}

int FileReadWriter::WriteToFile(int offset, const char * data) {
    if (!opened) 
        throw new FRWException(FAILED_TO_WRITE_FILE_NOT_OPEN, this->filename);
    
    int bytesWritten;
    if (lseek (this->fd, offset, SEEK_CUR) < 0 || (bytesWritten = write(this->fd, data, strlen(data)) ) < 0) 
        throw new FRWException(FAILED_TO_WRITE_TO_FILE, this->filename);

    return bytesWritten;
}

int FileReadWriter::ReadFromFile(char *data, int offset, int numberOfBytesToRead){
    if (!opened)
        throw new FRWException(FAILED_TO_READ_FILE_NOT_OPEN, filename);
    
    int bytesRead;

    if (lseek (fd, offset, SEEK_CUR) < 0 || ( bytesRead = read(fd, data, numberOfBytesToRead) ) < 0)  {
        throw new FRWException(FAILED_TO_READ_FROM_FILE, filename);
    }
    return bytesRead;
}

void FileReadWriter::Close(){
    if (!opened)
        throw new FRWException(FAILED_TO_CLOSE_FILE_NOT_OPEN, filename);
    if (close(fd) < 0)
        throw new FRWException(FAILED_TO_CLOSE_FILE, filename);
    opened = false;
}

const char * FileReadWriter::GetFileName() const {
    return filename;
}

int FileReadWriter::GetFileSize() const {
    return fileSize;
}

int FileReadWriter::GetFileDescriptor() const {
    if (!opened)
        throw new FRWException(FAILED_TO_GET_FD_NOT_OPEN, filename);
    return fd;
}


FileReadWriterStatus FileReadWriter::CheckFile(const char * filename, Mode::Type mode) {
      return (mode == Mode::READ) ? checkFileForRead(filename)
                            : checkFileForWrite(filename);
}

int FileReadWriter::GetFileSize(const char * filename) {
    struct stat st;
    if(stat(filename, &st) != 0) 
        throw new FRWException(FAILED_TO_GET_FILE_SIZE, filename);
    return st.st_size;
}

//CreateFile creates a file named filename of size fileSize in bytes
bool FileReadWriter::CreateFile(const char *filename, int fileSize, mode_t mode) {
    if (fileSize < 0)
        throw new FRWException(INVALID_FILE_SIZE, filename);

    // 0666 is to give all reading and writing permissions
    // TODO check why files arent being created with this permission
    int fd;
    if ( (fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, mode) ) < 0) {
        return false;
    }
    
    // resize the file to be the desired size of the incoming file being copied
    if (ftruncate(fd, fileSize) < 0 && close(fd) < 0) {
        return false;
    }
    return true; 
}

bool FileReadWriter::CheckFileIsDirectory(const char * filepath) {
    struct stat statbuf;
   if (stat(filepath, &statbuf) != 0)
       return false;
   return (bool) S_ISDIR(statbuf.st_mode);
}
//todo: make struct for your own mode
bool FileReadWriter::CreateDirectory(std::string dirname, mode_t mode) {
    return mkdir(dirname.c_str(), mode) == 0;
} 

bool FileReadWriter::RenameFile(std::string oldname, std::string newname) {
    return rename(oldname.c_str(), newname.c_str()) == 0;    
}   

bool FileReadWriter::DoesFileExist(std::string filePath) {
    return (access(filePath.c_str(), F_OK) == 0); 
}

bool FileReadWriter::CopyFileIntoDirectory(std::string directoryName, std::string filename, int fileSize) {
    std::string newSourcePath = directoryName + "/" + filename;
    return FileReadWriter::CreateFile(newSourcePath.c_str(), fileSize);
}

bool FileReadWriter::CopyDirectoryIntoDirectory(std::string destinationDirectory, std::string sourceDirectory) {
    std::string newSourcePath = destinationDirectory + "/" + sourceDirectory;
    if (!FileReadWriter::DoesFileExist(newSourcePath)){
        return FileReadWriter::CreateDirectory(newSourcePath.c_str());

    }   
    return true;

}


std::vector<File> FileReadWriter::GetFilesAtPath(std::string filePath) {
    std::vector<File> files;
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(filePath)) {
        File file(dirEntry.path().root_path().string(), (int) dirEntry.file_size(), dirEntry.is_directory());
        std::cout << "PATH: " << dirEntry.path().root_path().string() << std::endl;
        files.push_back(file);
    }
    return files;
}  

