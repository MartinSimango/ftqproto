#include "../include/FileIOException.hpp"

#include <cstring>
using namespace ftq_driver;

const char *FileIOException::what() const throw() { return error.c_str(); }

std::string FileIOException::getFilename() const { return filename; }

std::string FileIOException::getErrorMessage() {
	return "[Error] " + std::string(strerror(errno)) + "\n[FileIOException] Error: " + this->error +
		   "\n[FileIOException] File: " + this->filename;
}
