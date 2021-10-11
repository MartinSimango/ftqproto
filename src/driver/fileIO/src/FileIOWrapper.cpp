#include <cpperror/ErrorVoid.hpp>
#include "../include/FileIO.hpp"
#include "../include/FileIOWrapper.h"
#include <iostream>

using namespace ftq_driver;
using namespace error;

FileIO *AsFileReadWriter(void *frw) {
  return reinterpret_cast<FileIO *>(frw);
}

void *NewFileIO(const char *filename, char mode) {
  FileIO *frw;
  Mode::Type fileMode = Mode::WRITE;
  if ((int)mode == 0) {
    fileMode = Mode::READ;
  }
  frw = new FileIO(filename, fileMode);

  return frw;
}

void DestroyFileIO(void *frw) {
  AsFileReadWriter(frw)->~FileIO();
}

void *OpenFile(void *frw) {
  Error<void, FileIO> *error = new Error<void, FileIO>(
      &FileIO::Open, AsFileReadWriter(frw));
  error->Execute();

  return dynamic_cast<ErrorBase *>(error);
}

// Closes closes the file resource
void *CloseFile(void *frw) {
  Error<void, FileIO> *error = new Error<void, FileIO>(
      &FileIO::Close, AsFileReadWriter(frw));
  error->Execute();

  return dynamic_cast<ErrorBase *>(error);
}

void *WriteToFile(void *frw, int offset, const char *data) {
  Error<int, FileIO,const char *, int> *error =
      new Error<int, FileIO, const char *, int>(
          &FileIO::WriteToFile, AsFileReadWriter(frw));
  error->Execute(data, offset);

  return dynamic_cast<ErrorBase *>(error);
}

void *ReadFromFile(void *frw, char *data, int offset, int numberOfBytesToRead) {
  Error<int, FileIO, char *, int, int> *error =
      new Error<int, FileIO, char *, int, int>(
          &FileIO::ReadFromFile, AsFileReadWriter(frw));
  error->Execute(data, offset, numberOfBytesToRead);

  return dynamic_cast<ErrorBase *>(error);
}
