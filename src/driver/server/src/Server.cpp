#include <ftqproto/Server.hpp>

using namespace fts;

// Connect connects the client to the specific server
void FileServer::StartServer(int connections) {
	createAndBindServerSocket();
	if (listen(sockfd, connections) < 0)
		throw new ServerException(SERVER_FAILED_TO_START_LISTENING);
	isRunning = true;
}

void FileServer::Accept() {
	if (!isRunning) {
		throw new ServerException(SERVER_NOT_RUNNING);
	}

	struct sockaddr_in client;
	int len = sizeof(client);
	connfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&len);

	if (connfd < 0) {
		throw new ServerException(FAILED_TO_ACCEPT_CONNECTION);
	}
}

void FileServer::Close() {
	if (!isRunning)
		throw new ServerException(SERVER_NOT_RUNNING);
	if (close(connfd) < 0)
		throw new ServerException(FAILED_TO_CLOSE_CLIENT_SOCKET);
	if (close(sockfd) < 0)
		throw new ServerException(FAILED_TO_CLOSE_SERVER_SOCKET);

	isRunning = false;
}

// todo: rather return the client request and the make handleRequest public
bool FileServer::HandleClientRequest() {

	if (!isRunning) {
		throw new ServerException(SERVER_NOT_RUNNING);
	}
	Request request(connfd);

	int bytes = request.Read();

	if (bytes == 0) { // read nothing from the client then close
					  // the connection with it

		return false;
	}

	switch (request.requestType) {

	case RequestType::CREATE: {
		handleCreateRequest(requestFactory.CreateCreateRequest(request.message.c_str()));
		break;
	}
	case RequestType::GET: {
		handleGetRequest(requestFactory.CreateGetRequest(request.message.c_str()));
		break;
	}
	case RequestType::READ: {
		handleReadRequest(requestFactory.CreateReadRequest(request.message.c_str()));
		break;
	}
	case RequestType::WRITE: {
		handleWriteRequest(requestFactory.CreateWriteRequest(request.message.c_str()));
		break;
	}
	default: { // unknown request close connection
		return false;
		// todo log unknown request
	}
	}
	return true;
}

bool FileServer::IsServerRunning() { return isRunning; }
