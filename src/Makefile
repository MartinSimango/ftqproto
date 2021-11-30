CC=gcc
CPP=g++
CFLAGS=-std=c++17  -L ../build/lib/process -lpthread #-lprotobuf
ODIR=../build/obj
LDIR=../build/lib
ALL_HEADER_FILES:=$(wildcard */*/include/*.h*)
ALL_SOURCE_FILES:=$(wildcard */*/src/*.c*)

.PHONY: build main

###############  LIBRARIES  ###############

LIBRARIES=$(shell ls modules/)
MAKE_LIBRARY_DIRS:=$(patsubst %, %.libraries,$(LIBRARIES))
BUILD_LIBRARIES=$(patsubst %, %.build,$(LIBRARIES))

$(MAKE_LIBRARY_DIRS):
	mkdir -p ../build/obj/$(patsubst %.libraries,%,$@)
	mkdir -p ../build/lib/$(patsubst %.libraries,%,$@)

$(BUILD_LIBRARIES):
	$(MAKE) build -C modules/$(patsubst %.build,%,$@)

###############  EXECUTABLES  ###############

main: $(ALL_HEADER_FILES)
	$(CPP) -o ../bin/main  main.cpp -lftq-process  $(CFLAGS)


build: $(MAKE_LIBRARY_DIRS) $(BUILD_LIBRARIES)

clean:
	rm -rf ../build


###############  TOOLS   ###############

NPM:=/usr/local/bin/npm
CLANG_FORMAT:=/usr/local/bin/clang-format

format: check-tools
	clang-format -style=file -i $(ALL_SOURCE_FILES) $(ALL_HEADER_FILES)

$(NPM):
	@echo "You need to install npm first"

$(CLANG_FORMAT): $(NPM)
	sudo npm install -g clang-format

check-tools: $(CLANG_FORMAT) 

gen-clang-config:
	clang-format -style=llvm -dump-config > .clang-format.template.yaml

gen-modules:
	gen-modules -f modules.yaml -o modules  # TODO


