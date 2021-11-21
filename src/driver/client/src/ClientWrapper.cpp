#include <cpperror/ErrorVoid.hpp>
#include <ftqproto/Client.hpp>
#include <ftqproto/ClientWrapper.h>
#include <iostream>

using namespace ftc;
using namespace error;

FileClient *AsFileClient(void *fc) { return reinterpret_cast<FileClient *>(fc); }

void *NewFileClient() {
	FileClient *fc = new FileClient();
	return fc;
}

void DestroyFileClient(void *fc) { AsFileClient(fc)->~FileClient(); }

// Connect connects the client to the specific server specified by the
// ServerPort returns false if connect failed and errorMessage is set
void *Connect(void *fc, char *serverAddress, int port) {
	struct ServerPort serverPort;
	serverPort.port = port;
	strncpy(serverPort.serverAddress, serverAddress, sizeof(serverPort.serverAddress));
	Error<void, FileClient, ServerPort> *error =
		new Error<void, FileClient, ServerPort>(&FileClient::Connect, AsFileClient(fc));
	error->Execute(serverPort);
	return dynamic_cast<ErrorBase *>(error);
}

void *SendCreateRequest(void *fc, const char *protoCreateRequestMessage) {
	Error<std::string, FileClient, std::string> *error =
		new Error<std::string, FileClient, std::string>(&FileClient::SendCreateRequest,
														AsFileClient(fc));
	error->Execute(protoCreateRequestMessage);
	return dynamic_cast<ErrorBase *>(error);
}

void *SendGetRequest(void *fc, const char *protoGetRequestMessage) {
	Error<std::string, FileClient, std::string> *error =
		new Error<std::string, FileClient, std::string>(&FileClient::SendGetRequest,
														AsFileClient(fc));
	error->Execute(protoGetRequestMessage);

	return dynamic_cast<ErrorBase *>(error);
}

void *SendReadRequest(void *fc, const char *protoReadRequestMessage) {
	Error<std::string, FileClient, std::string> *error =
		new Error<std::string, FileClient, std::string>(&FileClient::SendReadRequest,
														AsFileClient(fc));
	error->Execute(protoReadRequestMessage);

	return dynamic_cast<ErrorBase *>(error);
}

void *SendWriteRequest(void *fc, const char *protoWriteRequestMessage) {
	Error<std::string, FileClient, std::string> *error =
		new Error<std::string, FileClient, std::string>(&FileClient::SendWriteRequest,
														AsFileClient(fc));
	error->Execute(protoWriteRequestMessage);

	return dynamic_cast<ErrorBase *>(error);
}

// CloseFileClient closes the connection to the server, returns false upon
// failure
void *CloseFileClient(void *fc) {
	Error<void, FileClient> *error =
		new Error<void, FileClient>(&FileClient::Close, AsFileClient(fc));
	error->Execute();

	return dynamic_cast<ErrorBase *>(error);
}
