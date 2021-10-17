#pragma once

#include <fcntl.h>
#include <filesystem>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#include "FileIOConstants.hpp"
#include "FileIOException.hpp"
#include "FileIOStatuses.hpp"

namespace ftq_driver {

struct File {
  std::string filepath;
  bool isDir;
  int fileSize;

  File(std::string filepath, int fileSize, bool isDir)
      : filepath(filepath), fileSize(fileSize), isDir(isDir) {}
};

class FileIO {

private:
  // todo rename ot filePath
  char filename[MAX_FILEPATH_LENGTH];
  Mode::Type mode;
  bool opened;
  int fd, fileSize;

  inline void openFileForReading() {
    if ((this->fd = open(this->filename, O_RDONLY)) < 0)
      throw new FileIOException(FAILED_TO_OPEN_FILE_FOR_READING,
                                this->filename);
    opened = true;
  }

  inline void openFileForWriting() {
    if ((this->fd = open(this->filename, O_WRONLY)) < 0)
      throw new FileIOException(FAILED_TO_OPEN_FILE_FOR_WRITING,
                                this->filename);
    opened = true;
  }

  static inline FileIOStatus checkFileForRead(std::string filePath) {
    if (access(filePath.c_str(), F_OK) == 0) {
      return access(filePath.c_str(), R_OK) == 0
                 ? FileIOStatus::OK
                 : FileIOStatus::NO_READ_PERMISSIONS;
    } else {
      return FileIOStatus::FILE_NOT_FOUND;
    }
  }

  static inline FileIOStatus checkFileForWrite(std::string filepath) {
    // check if parent directory exists
    std::string parentDir = std::string(dirname(&filepath[0]));

    if (access(parentDir.c_str(), F_OK) != 0) {
      return FileIOStatus::FILE_NOT_FOUND;
    }
    if (access(filepath.c_str(), F_OK) == 0) {
      return access(filepath.c_str(), W_OK) == 0
                 ? FileIOStatus::OK
                 : FileIOStatus::NO_WRITE_PERMISSIONS;
    }
    return FileIOStatus::OK;
  }

public:
  FileIO(std::string filename, Mode::Type mode) : mode(mode), opened(false) {
    strncpy(this->filename, filename.c_str(), sizeof(this->filename));
  }

  ~FileIO() {}

  /**
   *  Open opens the file resource and sets the internal file descriptor
   */
  void Open();

  /**
   * WriteToFile get the size of file in bytes
   * @param data data to be written to the file
   * @param offset offset of where to begin writing to a file
   * @return the number of bytes written
   */
  int WriteToFile(const char *data, int offset);

  /**
   * ReadFromFile get the size of file in bytes
   * @param data pointer to data read from the file
   * @param offset offset of where to begin reading from the opened file
   * @return the number of bytes read
   */
  int ReadFromFile(char *data, int offset, int numberOfBytesToRead);

  /**
   *  Closes closes the file resource
   */
  void Close();

  /**
   * GetFileName returns the name of the file the object is associated to.
   */
  const char *GetFileName() const;

  /**
   * GetFileName returns the size of the file (in bytes) the object is
   * associated to.
   */
  int GetFileSize() const;

  /**
   * GetFileName returns the file desriptoer of the file the object is
   * associated to.
   */
  int GetFileDescriptor() const;

  /**
   * CheckFile checks to see if a file located at filePath can either be read of
   * written
   * @param filePath path of file
   * @param mode determines whether check file will check for read or write
   * permissions
   * @return a FileReadWriterStatus
   */
  static FileIOStatus CheckFile(std::string filePath, Mode::Type mode);

  /**
   * CheckFileIsDirectory checks
   * @param filePath absolute path of the old filename
   * @return true if the operation is successful otherwise false
   */
  static bool CheckFileIsDirectory(const char *filename);

  /**
   * GetFileSize get the size of file at filePath in bytes
   * @param filePath path of file
   * @return true if the operation is successful otherwise false
   */
  static int GetFileSize(std::string filePath);

  /**
   * CreateFile creates a file of a specific size.
   * @param filname name/path of file
   * @param fileSize file size in bytes
   * @param mode file permissions (optional - defaults to 0666)
   * @return true if the operation is successful otherwise false
   */
  static bool CreateFile(std::string filename, int fileSize,
                         mode_t mode = 0666); // todo implement mode

  /**
   * CreateDirectory creates a directory at a specified path
   * @param dirname path of directory to be created
   * @param mode directory permissions (optional defaults to 0777)
   * @return true if the operation is successful otherwise false
   */
  static bool CreateDirectory(std::string dirname,
                              mode_t mode = S_IRWXU | S_IRWXG |
                                            S_IRWXO); // todo implement mode

  /**
   * ReanameFile renames a file
   * @param oldName path of the old filename
   * @param newName path of the new filename
   * @return true if the operation is successful otherwise false
   */
  static bool RenameFile(std::string oldname, std::string newName);

  /**
   * DoesFileExist checks the existence of a file.
   * @param filePath path of the file
   * @return true if the file exists, otherwise false
   */
  static bool DoesFileExist(std::string filePath);

  /**
   * CopyFileIntoDirectory copies a file into a directory
   * @param directoryFilePath the destination directory file path
   * @param filePath the filepath of the file to be copied into the directory
   * @param fileSize the size of the file in bytes to be copied
   * @return true if the file at filepath is successfully copied, otherwise
   * false
   */
  static bool CopyFileIntoDirectory(std::string directoryFilePath,
                                    std::string filePath, int fileSize);

  /**
   * CopyDirectoryIntoDirectory copies a directory into another directory
   * @param destinationDirectory the destination directory
   * @param sourceDirectory the source directory
   * @return true if the source directory was copied, otherwise false
   */
  static bool CopyDirectoryIntoDirectory(std::string destinationDirectory,
                                         std::string sourceDirectory);

  /**
   * GetFilesAtPath returns of vectors of Files located at a specific filepath.
   * @param filePath the query filepath
   * @return a vector of File ohjects representing a list of files
   */
  static std::vector<File> GetFilesAtPath(std::string filePath);
};

} // namespace ftq_driver