#include "../include/FRWException.hpp"

using namespace ftq_driver;

const char *FRWException::what() const throw() { return error.c_str(); }

std::string FRWException::getFilename() const { return filename; }

std::string FRWException::getErrorMessage() {
  return "[Error] " + std::string(strerror(errno)) +
         "\n[FRWException] Error: " + this->error +
         "\n[FRWException] File: " + this->filename;
}
