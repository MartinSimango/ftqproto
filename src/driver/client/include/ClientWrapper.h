
#pragma once
#include <stdbool.h>

#define READ_MODE 0
#define WRITE_MODE 1

 
#pragma once
#include <stdbool.h>

#define READ_MODE 0
#define WRITE_MODE 1

 
#ifdef __cplusplus	
extern "C" {	
#endif	


void* NewFileClient();	

void DestroyFileClient(void* fc);	

// Connect connects the client to the specific server specified by the ServerPort 	
void * Connect(void* fc, char * serverAddress, int port);	

void * SendCreateRequest(void* fc, const char * protoCreateRequestMessage); 	

void * SendGetRequest(void* fc, const char * protoGetRequestMessage);	

void * SendReadRequest(void* fc, const char * protoReadRequestMessage);	

void * SendWriteRequest(void* fc, const char * protoWriteRequestMessage);	

// CloseFileClient closes the connection to the server, returns false upon failure	
void * CloseFileClient(void* fc);	


#ifdef __cplusplus	
}  // extern "C"	
#endif	

