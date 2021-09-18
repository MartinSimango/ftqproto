CC=gcc
CPP=g++
CFLAGS=-std=c++17 -lprotobuf
ALL_HEADER_FILES=$(wildcard */*/include/*.h*)
ALL_SOURCE_FILES=$(wildcard */*/src/*.c*)

PROCESS_HEADER_FILES=$(wildcard ../src/*/process/include/*.h*)
PROCESS_SOURCE_FILES=$(wildcard ../src/*/process/src/*.c*)



process: $(PROCESS_HEADER_FILES)
	$(CPP) -o test $(PROCESS_SOURCE_FILES) main.cpp $(CFLAGS)