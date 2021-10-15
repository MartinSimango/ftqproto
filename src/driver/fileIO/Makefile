CC=gcc
CPP=g++
IDIR=include
ODIR=obj
LDIR=lib
SDIR=src
INCDIR=include
CFLAGS=-std=c++17
LIBNAME=libftqio

FRW_SOURCES=$(wildcard $(SDIR)/*.cpp)
FRW_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(FRW_SOURCES))

FRW_DEPS = $(wildcard $(IDIR)/*) 
FRW_DLIB_SOURCES= $(FRW_SOURCES)

FRW_HEADERS = $(wildcard $(INCDIR)/*)
FRW_UNINSTALL_HEADERS = $(patsubst $(INCDIR)/%, %, $(FRW_HEADERS)) 

.PHONY: $(FRW_UNINSTALL_HEADERS) clean

build: build-dir build-objects build-lib

build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)

build-objects: $(FRW_OBJECTS)

$(FRW_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(FRW_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)

build-lib: $(FRW_OBJECTS)
	ar -crs $(LDIR)/$(LIBNAME).a $(FRW_OBJECTS) #build the static library
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(FRW_DLIB_SOURCES) $(CFLAGS)

install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	
install-headers:
	cp include/* /usr/local/include/ftqproto

uninstall: $(FRW_UNINSTALL_HEADERS)
	rm -f /usr/local/lib/$(LIBNAME).so

$(FRW_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/ftqproto/$@

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)