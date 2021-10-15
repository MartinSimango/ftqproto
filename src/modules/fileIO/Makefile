CC=gcc
CPP=g++
CFLAGS=-std=c++17 #-lprotobuf
ODIR=../../../build/obj
LDIR=../../../build/lib


.PHONY: build

MODULE_NAME=fileIO
LIB_NAME=libftq-fileIO


DRIVER:=../../driver/$(MODULE_NAME)/src/%.cpp
ADAPTER:=../../adapter/$(MODULE_NAME)/src/%.cpp
USECASE:=../../usecase/$(MODULE_NAME)/src/%.cpp
DOMAIN:=../../domain/$(MODULE_NAME)/src/%.cpp


HEADER_FILES:=$(wildcard ../../*/$(MODULE_NAME)/include/*.h*)
SOURCE_FILES:=$(wildcard ../../*/$(MODULE_NAME)/src/*.c*)
RELATIVE_SOURCE_FILES:=$(foreach file, $(SOURCE_FILES), $(notdir $(file)))
OBJECT_FILES:=$(patsubst %.cpp, $(ODIR)/$(MODULE_NAME)/%.o, $(RELATIVE_SOURCE_FILES))

DEPENDENCIES:=

$(OBJECT_FILES): $(ODIR)/$(MODULE_NAME)/%.o : $(DRIVER) $(DEPENDENCIES)
	$(CPP) -c $< -o $@ $(CFLAGS)

build-library: $(OBJECT_FILES)
	echo $(RELATIVE_SOURCE_FILES)
	ar -crs $(LDIR)/fileIO/$(LIB_NAME).a $(OBJECT_FILES)
	$(CPP) -shared -fPIC -o $(LDIR)/$(MODULE_NAME)/$(LIB_NAME).so $(SOURCE_FILES) $(CFLAGS)

build: build-library

install: