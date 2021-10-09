CC=gcc
CPP=g++
CFLAGS=-std=c++17 -lprotobuf
ALL_HEADER_FILES:=$(wildcard */*/include/*.h*)
ALL_SOURCE_FILES:=$(wildcard */*/src/*.c*)

PROCESS_HEADER_FILES=$(wildcard */process/include/*.h*)
PROCESS_SOURCE_FILES=$(wildcard */process/src/*.c*)

#tools
NPM:=/usr/local/bin/npm
CLANG_FORMAT:=/usr/local/bin/clang-format


process: $(PROCESS_HEADER_FILES)
	$(CPP) -o main $(PROCESS_SOURCE_FILES) main.cpp $(CFLAGS)

format: check-tools
	clang-format -style=llvm -i $(ALL_SOURCE_FILES) $(ALL_HEADER_FILES)

########## Tools #########

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

