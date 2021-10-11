#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void *NewFileIO(const char *filename, char mode);

void DestroyFileIO(void *frw);

void *OpenFile(void *frw);

void *WriteToFile(void *frw, int offset, const char *data);

void *ReadFromFile(void *frw, char *data, int offset, int numberOfBytesToRead);

// Closes closes the file resource
void *CloseFile(void *frw);

#ifdef __cplusplus
} // extern "C"
#endif