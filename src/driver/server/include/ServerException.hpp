#pragma once
#include "../../../domain/exception/include/Exception.hpp"
#include <errno.h>

namespace ftq_driver {

static std::string FAILED_TO_BIND_SERVER_SOCKET = "Failed to bind the server socket.";
static std::string FAILED_TO_CREATE_SERVER_SOCKET = "Failed to create the server socket!";
static std::string SERVER_FAILED_TO_START_LISTENING = "Server failed to start listening!";
static std::string SERVER_NOT_RUNNING = "The server is not running!";
static std::string FAILED_TO_CLOSE_SERVER_SOCKET = "Failed to close the server socket.";
static std::string FAILED_TO_CLOSE_CLIENT_SOCKET = "Failed to close the server socket.";
static std::string FAILED_TO_ACCEPT_CONNECTION = "Failed accept connection.";

class ServerException : public ftq_domain::Exception {

  private:
	std::string error;

  public:
	ServerException(std::string error) : ftq_domain::Exception(), error(error) {}

	const char *what() const throw() override { return error.c_str(); }

	std::string getErrorMessage() override {
		return "[Error] " + std::string(strerror(errno)) +
			   "\n[ServerException] Error: " + this->error;
	}
};

} // namespace ftq_domain