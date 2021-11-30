CC=gcc
CPP=g++
CFLAGS=-std=c++17
ODIR=../../../build/obj
LDIR=../../../build/lib


.PHONY: build

MODULE_NAME=process
LIB_NAME=libftq-process

DRIVER:=../../driver/$(MODULE_NAME)/src/%.cpp
ADAPTER:=../../adapter/$(MODULE_NAME)/src/%.cpp
USECASE:=../../usecase/$(MODULE_NAME)/src/%.cpp
DOMAIN:=../../domain/$(MODULE_NAME)/src/%.cpp


HEADER_FILES:=$(wildcard ../../*/$(MODULE_NAME)/include/*.h*)

# SOURCE FILES
SOURCE_FILES:=$(wildcard ../../*/$(MODULE_NAME)/src/*.c*)
DRIVER_SOURCE_FILES:=$(wildcard ../../driver/$(MODULE_NAME)/src/*.c*)
DOMAIN_SOURCE_FILES:=$(wildcard ../../domain/$(MODULE_NAME)/src/*.c*)
ADAPTER_SOURCE_FILES:=$(wildcard ../../adapter/$(MODULE_NAME)/src/*.c*)
USECASE_SOURCE_FILES:=$(wildcard ../../usecase/$(MODULE_NAME)/src/*.c*)

# OBJECT FILES
DRIVER_OBJECT_FILES:=$(patsubst %.cpp, $(ODIR)/$(MODULE_NAME)/%.o, $(notdir $(DRIVER_SOURCE_FILES)))
DOMAIN_OBJECT_FILES:=$(patsubst %.cpp, $(ODIR)/$(MODULE_NAME)/%.o, $(notdir $(DOMAIN_SOURCE_FILES)))
ADAPTER_OBJECT_FILES:=$(patsubst %.cpp, $(ODIR)/$(MODULE_NAME)/%.o, $(notdir $(ADAPTER_SOURCE_FILES)))
USECASE_OBJECT_FILES:=$(patsubst %.cpp, $(ODIR)/$(MODULE_NAME)/%.o, $(notdir $(USECASE_SOURCE_FILES)))

OBJECT_FILES:=$(DRIVER_OBJECT_FILES) $(DOMAIN_OBJECT_FILES) $(ADAPTEER_OBJECT_FILES) $(USECASE_OBJECT_FILES)

#DEPENDENCIES 
DRIVER_DEPENDENCIES:=
DOMAIN_DEPENDENCIES:=../../domain/logger/src/Logger.cpp
ADAPTER_DEPENDENCIES:=
USECASE_DEPENDENCIES:=

DEPENDENCIES:=$(DRIVER_DEPENDENCIES) $(DOMAIN_DEPENDENCIES) $(ADAPTER_DEPENDENCIES) $(USECASE_DEPENDENCIES)

$(DRIVER_OBJECT_FILES): $(ODIR)/$(MODULE_NAME)/%.o : $(DRIVER) $(DRIVER_DEPENDENCIES)
	$(CPP) -c $< -o $@ $(CFLAGS)

$(DOMAIN_OBJECT_FILES): $(ODIR)/$(MODULE_NAME)/%.o : $(DOMAIN) $(DOMAIN_DEPENDENCIES)
	$(CPP) -c $< -o $@ $(CFLAGS)

$(ADAPTER_OBJECT_FILES): $(ODIR)/$(MODULE_NAME)/%.o : $(ADAPTER) $(ADAPTER_DEPENDENCIES)
	$(CPP) -c $< -o $@ $(CFLAGS)

$(USECASE_OBJECT_FILES): $(ODIR)/$(MODULE_NAME)/%.o : $(USECASE) $(USECASE_DEPENDENCIES)
	$(CPP) -c $< -o $@ $(CFLAGS)

build-library: $(OBJECT_FILES)
	ar -crs $(LDIR)/$(MODULE_NAME)/$(LIB_NAME).a $(OBJECT_FILES)
	$(CPP) -shared -fPIC -o $(shell pwd)/$(LDIR)/$(MODULE_NAME)/$(LIB_NAME).so $(SOURCE_FILES) $(DEPENDENCIES) $(CFLAGS)

build: build-library

install:
	sudo cp $(LDIR)/$(MODULE_NAME)/$(LIB_NAME).so %s