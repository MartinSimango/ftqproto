#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void *NewFileReadWriter(const char *filename, char mode);

void DestroyFileReadWriter(void *frw);

void *OpenFile(void *frw);

void *WriteToFile(void *frw, int offset, const char *data);

void *ReadFromFile(void *frw, char *data, int offset, int numberOfBytesToRead);

// Closes closes the file resource
void *CloseFile(void *frw);

#ifdef __cplusplus
} // extern "C"
#endif