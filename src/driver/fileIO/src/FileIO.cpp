#include "../include/FileIO.hpp"
#include <stdio.h>

using namespace ftq_driver;

void FileIO::Open() {
	if (opened) {
		throw new FileIOException(FAILED_TO_OPEN_FILE_ALREADY_OPEN, filename);
	}
	(mode == Mode::READ) ? openFileForReading() : openFileForWriting();
	opened = true;
}

int FileIO::WriteToFile(const char *data, int offset) {
	if (!opened)
		throw new FileIOException(FAILED_TO_WRITE_FILE_NOT_OPEN, this->filename);

	int bytesWritten;
	if (lseek(this->fd, offset, SEEK_CUR) < 0 ||
		(bytesWritten = write(this->fd, data, strlen(data))) < 0)
		throw new FileIOException(FAILED_TO_WRITE_TO_FILE, this->filename);

	return bytesWritten;
}

int FileIO::ReadFromFile(char *data, int offset, int numberOfBytesToRead) {
	if (!opened)
		throw new FileIOException(FAILED_TO_READ_FILE_NOT_OPEN, filename);

	int bytesRead;

	if (lseek(fd, offset, SEEK_CUR) < 0 || (bytesRead = read(fd, data, numberOfBytesToRead)) < 0) {
		throw new FileIOException(FAILED_TO_READ_FROM_FILE, filename);
	}
	return bytesRead;
}

void FileIO::Close() {
	if (!opened)
		throw new FileIOException(FAILED_TO_CLOSE_FILE_NOT_OPEN, filename);
	if (close(fd) < 0)
		throw new FileIOException(FAILED_TO_CLOSE_FILE, filename);
	opened = false;
}

const char *FileIO::GetFileName() const { return filename; }

int FileIO::GetFileSize() const { return fileSize; }

int FileIO::GetFileDescriptor() const {
	if (!opened)
		throw new FileIOException(FAILED_TO_GET_FD_NOT_OPEN, filename);
	return fd;
}

FileIOStatus FileIO::CheckFile(std::string filePath, Mode::Type mode) {
	return (mode == Mode::READ) ? checkFileForRead(filePath) : checkFileForWrite(filePath);
}

int FileIO::GetFileSize(std::string filePath) {
	struct stat st;
	if (stat(filePath.c_str(), &st) != 0)
		throw new FileIOException(FAILED_TO_GET_FILE_SIZE, filePath);
	return st.st_size;
}

bool FileIO::CreateFile(std::string filename, int fileSize, mode_t mode) {
	if (fileSize < 0)
		throw new FileIOException(INVALID_FILE_SIZE, filename);

	// 0666 is to give all reading and writing permissions
	// TODO check why files arent being created with this
	// permission
	int fd;
	if ((fd = open(filename.c_str(), O_CREAT | O_TRUNC | O_WRONLY, mode)) < 0) {
		return false;
	}

	// resize the file to be the desired size of the incoming
	// file being copied
	if (ftruncate(fd, fileSize) < 0 && close(fd) < 0) {
		return false;
	}
	return true;
}

bool FileIO::CheckFileIsDirectory(const char *filepath) {
	struct stat statbuf;
	if (stat(filepath, &statbuf) != 0)
		return false;
	return (bool)S_ISDIR(statbuf.st_mode);
}
// todo: make struct for your own mode
bool FileIO::CreateDirectory(std::string dirname, mode_t mode) {
	return mkdir(dirname.c_str(), mode) == 0;
}

bool FileIO::RenameFile(std::string oldname, std::string newName) {
	return rename(oldname.c_str(), newName.c_str()) == 0;
}

bool FileIO::DoesFileExist(std::string filePath) { return (access(filePath.c_str(), F_OK) == 0); }

bool FileIO::CopyFileIntoDirectory(std::string directoryPath, std::string filepath, int fileSize) {
	std::string newSourcePath = directoryPath + "/" + filepath;
	return FileIO::CreateFile(newSourcePath.c_str(), fileSize);
}

bool FileIO::CopyDirectoryIntoDirectory(std::string destinationDirectory,
										std::string sourceDirectory) {
	std::string newSourcePath = destinationDirectory + "/" + sourceDirectory;
	if (!FileIO::DoesFileExist(newSourcePath)) {
		return FileIO::CreateDirectory(newSourcePath.c_str());
	}
	return true;
}

std::vector<File> FileIO::GetFilesAtPath(std::string filePath) {
	std::vector<File> files;
	for (const auto &dirEntry : std::filesystem::recursive_directory_iterator(filePath)) {
		File file(dirEntry.path().root_path().string(), (int)dirEntry.file_size(),
				  dirEntry.is_directory());
		std::cout << "PATH: " << dirEntry.path().root_path().string() << std::endl;
		files.push_back(file);
	}
	return files;
}
