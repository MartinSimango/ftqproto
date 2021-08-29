CC=gcc
CPP=g++
CFLAGS=-std=c++17 -lprotobuf
ALL_HEADER_FILES=$(wildcard */*/include/*.h*)
ALL_SOURCE_FILES=$(wildcard */*/src/*.c*)

PROCESS_HEADER_FILES=$(wildcard */process/include/*.h*)
PROCESS_SOURCE_FILES=$(wildcard */process/src/*.c*)



process: $(PROCESS_HEADER_FILES)
	$(CPP) -o main $(PROCESS_SOURCE_FILES) main.cpp $(CFLAGS)

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

