#include <cpperror/ErrorVoid.hpp>
#include <ftqproto/FileReadWriter.hpp>
#include <ftqproto/FileReadWriterWrapper.h>
#include <iostream>

using namespace frw;
using namespace error;

FileReadWriter *AsFileReadWriter(void *frw) {
  return reinterpret_cast<FileReadWriter *>(frw);
}

void *NewFileReadWriter(const char *filename, char mode) {
  FileReadWriter *frw;
  Mode::Type fileMode = Mode::WRITE;
  if ((int)mode == 0) {
    fileMode = Mode::READ;
  }
  frw = new FileReadWriter(filename, fileMode);

  return frw;
}

void DestroyFileReadWriter(void *frw) {
  AsFileReadWriter(frw)->~FileReadWriter();
}

void *OpenFile(void *frw) {
  Error<void, FileReadWriter> *error = new Error<void, FileReadWriter>(
      &FileReadWriter::Open, AsFileReadWriter(frw));
  error->Execute();

  return dynamic_cast<ErrorBase *>(error);
}

// Closes closes the file resource
void *CloseFile(void *frw) {
  Error<void, FileReadWriter> *error = new Error<void, FileReadWriter>(
      &FileReadWriter::Close, AsFileReadWriter(frw));
  error->Execute();

  return dynamic_cast<ErrorBase *>(error);
}

void *WriteToFile(void *frw, int offset, const char *data) {
  Error<int, FileReadWriter, int, const char *> *error =
      new Error<int, FileReadWriter, int, const char *>(
          &FileReadWriter::WriteToFile, AsFileReadWriter(frw));
  error->Execute(offset, data);

  return dynamic_cast<ErrorBase *>(error);
}

void *ReadFromFile(void *frw, char *data, int offset, int numberOfBytesToRead) {
  Error<int, FileReadWriter, char *, int, int> *error =
      new Error<int, FileReadWriter, char *, int, int>(
          &FileReadWriter::ReadFromFile, AsFileReadWriter(frw));
  error->Execute(data, offset, numberOfBytesToRead);

  return dynamic_cast<ErrorBase *>(error);
}
