#pragma once
#include <cpperror/ErrorException.hpp>

namespace ftq_driver {

static std::string FAILED_TO_RESIZE_FILE = "Failed to resize file.";
static std::string INVALID_FILE_SIZE = "A valid file size needs to be "
									   "specified when creating a file.";
static std::string FAILED_TO_GET_FILE_SIZE = "Failed to get file size";

static std::string FAILED_TO_OPEN_FILE_FOR_WRITING = "Failed to open file for writing.";
static std::string FAILED_TO_OPEN_FILE_FOR_READING = "Failed to open file for reading.";
static std::string FAILED_TO_CREATE_FILE_ = "Failed to create file.";
static std::string FAILED_TO_CREATE_DIRECTORY_ = "Failed to create directory.";

static std::string FAILED_TO_CLOSE_FILE = "Failed to close file.";
static std::string FAILED_TO_OPEN_FILE_ALREADY_OPEN =
	"Failed to open file as file is already open.";

static std::string FAILED_TO_READ_FROM_FILE = "Failed to read from file.";
static std::string FAILED_TO_WRITE_TO_FILE = "Failed to write to file.";
static std::string FAILED_TO_WRITE_TO_DIRECTORY = "Failed to write to directory.";
static std::string FAILED_TO_WRITE_FILE_NOT_OPEN = "Cannot write to unopened file.";
static std::string FAILED_TO_READ_FILE_NOT_OPEN = "Cannot read to unopened file.";
static std::string FAILED_TO_CLOSE_FILE_NOT_OPEN = "Cannot close unopened file.";
static std::string FAILED_TO_GET_FD_NOT_OPEN =
	"Cannot get file descriptor of closed or unopened file.";

class FileIOException : public error::ErrorException {

  private:
	std::string error;
	std::string filename;

  public:
	FileIOException(std::string error, std::string filename)
		: error::ErrorException(), error(error), filename(filename) {}

	const char *what() const throw() override;

	/**
	 * getFilename returns the filename/filepath relating to the
	 * thrown exception
	 */
	std::string getFilename() const;

	/**
	 * getErrorMessge returns the error message that caused the
	 exception to be
	 * thrown

	 */
	std::string getErrorMessage() override;
};
} // namespace ftq_driver
