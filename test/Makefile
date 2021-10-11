CC=gcc
CPP=g++
CFLAGS=-std=c++17 -lprotobuf
ALL_HEADER_FILES=$(wildcard */*/*.h*) $(wildcard */*.h*) $(wildcard *.h*)
ALL_SOURCE_FILES=$(wildcard */*/*.c*) $(wildcard */*.c*) $(wildcard *.c*)

PROCESS_HEADER_FILES=$(wildcard ../src/*/process/include/*.h*)
PROCESS_SOURCE_FILES=$(wildcard ../src/*/process/src/*.c*)

FILEIO_HEADER_FILES=$(wildcard ../src/*/fileIO/include/*.h*)
FILEIO_SOURCE_FILES=$(wildcard ../src/*/fileIO/src/*.c*)

.PHONY: test

test: $(PROCESS_HEADER_FILES) $(FILEIO_HEADER_FILES)
	@rm -rf /tmp/ftqproto_tests
	@mkdir /tmp/ftqproto_tests
	$(CPP) -o test $(PROCESS_SOURCE_FILES) $(FILEIO_SOURCE_FILES) main.cpp $(CFLAGS)

format: check-tools
	clang-format -style=llvm -i $(ALL_SOURCE_FILES) $(ALL_HEADER_FILES)

########## Tools #########

$(NPM):
	@echo "You need to install npm first"

$(CLANG_FORMAT): $(NPM)
	sudo npm install -g clang-format

check-tools: $(CLANG_FORMAT) 