CC=gcc
CPP=g++
CFLAGS=-std=c++17 #-lprotobuf
ODIR=../build/obj
LDIR=../build/lib
ALL_HEADER_FILES:=$(wildcard */*/include/*.h*)
ALL_SOURCE_FILES:=$(wildcard */*/src/*.c*)

.PHONY: build main

###############  LIBRARIES  ###############

LIBRARIES:=$(shell ls modules/)
MAKE_LIBRARY_DIRS:=$(patsubst %, %.libraries,$(LIBRARIES))
BUILD_LIBRARIES:=$(patsubst %, %.build,$(LIBRARIES))

$(MAKE_LIBRARY_DIRS):
	mkdir -p ../build/obj/$(patsubst %.libraries,%,$@)
	mkdir -p ../build/lib/$(patsubst %.libraries,%,$@)

$(BUILD_LIBRARIES):
	$(MAKE) build -C modules/$(patsubst %.build,%,$@)

main: $(ALL_HEADER_FILES)
	$(CPP) -o main $(PROCESS_SOURCE_FILES) main.cpp $(CFLAGS)


build: $(MAKE_LIBRARY_DIRS) $(BUILD_LIBRARIES)

clean:
	rm -rf ../build


###############  TOOLS   ###############

NPM:=/usr/local/bin/npm
CLANG_FORMAT:=/usr/local/bin/clang-format

format: check-tools
	clang-format -style=llvm -i $(ALL_SOURCE_FILES) $(ALL_HEADER_FILES)

$(NPM):
	@echo "You need to install npm first"

$(CLANG_FORMAT): $(NPM)
	sudo npm install -g clang-format

check-tools: $(CLANG_FORMAT) 

gen-clang-config:
	clang-format -style=llvm -dump-config > .clang-format

# all: 
# 	echo $(PROCESS_HEADER_FILES)
	
# define IDIR

# ./include  ../Request/include ../Response/include ../FileReadWriter/include ../Serializer/include


# endef
# ODIR=obj
# LDIR=lib
# SDIR=src
# INCDIR=include
# CFLAGS=-std=c++17 -lprotobuf
# LIBNAME=libgocpclient


# CLIENT_SOURCES=$(wildcard $(SDIR)/*.cpp)
# CLIENT_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CLIENT_SOURCES))

# define CLIENT_DLIB_SOURCES
# $(CLIENT_SOURCES) ../Request/src/*.cpp ../Response/src/*.cpp ../FileReadWriter/src/*.cpp ../Request/gen/ftqproto/*.cc
# endef

# CLIENT_DEPS = $(wildcard $(IDIR)/*) 

# CLIENT_HEADERS = $(wildcard $(INCDIR)/*)
# CLIENT_UNINSTALL_HEADERS=$(patsubst $(INCDIR)/%, %, $(CLIENT_HEADERS)) 

