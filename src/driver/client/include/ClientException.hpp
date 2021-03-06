#pragma once
#include <cpperror/ErrorException.hpp>
static const char *FAILED_TO_BIND_SERVER_SOCKET = "Failed to bind the server socket.";
static const char *FAILED_TO_CONNECT_TO_SERVER = "Failed to connect to the server.";

static const char *FAILED_TO_CREATE_CLIENT_SOCKET = "Failed to create the client socket.";
static const char *CLIENT_NOT_CONNECTED = "The client is not connected to the server.";
static const char *CLIENT_ALREADY_CONNECTED = "The client is already connected to a server.";
static const char *FAILED_TO_CLOSE_CLIENT_SOCKET = "Failed to close the client socket.";

class ClientException : public error::ErrorException {

  private:
	const char *error;

  public:
	ClientException(const char *error) : error::ErrorException(), error(error) {}

	const char *what() const throw() override { return error; }

	std::string getErrorMessage() override {
		return "[Error] " + std::string(strerror(errno)) +
			   "\n[ClientException] Error: " + this->error;
	}
};
