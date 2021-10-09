#pragma once
#include <fcntl.h>
#include <filesystem>
#include <ftqproto/FRWException.hpp>
#include <ftqproto/FileReadWriterConstants.hpp>
#include <ftqproto/FileReadWriterStatuses.hpp>
#include <ftqproto/ResponseConstants.hpp>
#include <ftqproto/ResponseStatus.pb.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace response;

namespace ftq_domain {

struct File {
  std::string filepath;
  bool isDir;
  int fileSize;

  File(std::string filepath, int fileSize, bool isDir)
      : filepath(filepath), fileSize(fileSize), isDir(isDir) {}
};

class FileReadWriter {

private:
  char filename[MAX_FILEPATH_LENGTH];
  Mode::Type mode;
  bool opened;
  int fd, fileSize;

  inline void openFileForReading() {
    if ((this->fd = open(this->filename, O_RDONLY)) < 0)
      throw new FRWException(FAILED_TO_OPEN_FILE_FOR_READING, this->filename);
    opened = true;
  }

  inline void openFileForWriting() {
    if ((this->fd = open(this->filename, O_WRONLY)) < 0)
      throw new FRWException(FAILED_TO_OPEN_FILE_FOR_WRITING, this->filename);
    opened = true;
  }

  static inline FileReadWriterStatus checkFileForRead(const char *filename) {
    if (access(filename, F_OK) == 0) {
      return access(filename, R_OK) == 0
                 ? FileReadWriterStatus::OK
                 : FileReadWriterStatus::NO_READ_PERMISSIONS;
    } else {
      return FileReadWriterStatus::FILE_NOT_FOUND;
    }
  }

  static inline FileReadWriterStatus checkFileForWrite(std::string filepath) {
    // check if parent directory exists
    std::string parentDir = std::string(dirname(&filepath[0]));

    if (access(parentDir.c_str(), F_OK) != 0) {
      return FileReadWriterStatus::FILE_NOT_FOUND;
    }
    if (access(filepath.c_str(), F_OK) == 0) {
      return access(filepath.c_str(), W_OK) == 0
                 ? FileReadWriterStatus::OK
                 : FileReadWriterStatus::NO_WRITE_PERMISSIONS;
    }
    return FileReadWriterStatus::OK;
  }

public:
  FileReadWriter(const char *filename, Mode::Type mode)
      : mode(mode), opened(false) {
    strncpy(this->filename, filename, sizeof(this->filename));
  }

  ~FileReadWriter() {}

  // Open opens the file resource
  void Open();

  int WriteToFile(int offset, const char *data);

  int ReadFromFile(char *data, int offset, int numberOfBytesToRead);

  // Closes closes the file resource
  void Close();

  const char *GetFileName() const;

  int GetFileSize() const;

  int GetFileDescriptor() const;

  // TODO return FRW STATUS, FRW should have no idea about responst status
  static FileReadWriterStatus CheckFile(const char *filename, Mode::Type mode);

  static bool CheckFileIsDirectory(const char *filename);

  static int GetFileSize(const char *filename);

  static bool CreateFile(const char *filename, int fileSize,
                         mode_t mode = 0666); // todo implement mode

  // CreateDirectory creates a directory at the path specified by dirname
  static bool CreateDirectory(std::string dirname,
                              mode_t mode = S_IRWXU | S_IRWXG |
                                            S_IRWXO); // todo implement mode

  static bool RenameFile(std::string oldname, std::string newname);

  static bool DoesFileExist(std::string filePath);

  static bool CopyFileIntoDirectory(std::string directoryName,
                                    std::string sourceFile, int fileSize);

  static bool CopyDirectoryIntoDirectory(std::string destinationDirectory,
                                         std::string sourceDirectory);

  static std::vector<File> GetFilesAtPath(std::string filePath);
};

} // namespace ftq_domain