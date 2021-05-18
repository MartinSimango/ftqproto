CC=gcc
CPP=g++
IDIR=include ../Response/include
ODIR=obj
LDIR=lib
SDIR=src
CFLAGS=$(patsubst %, -I%, $(IDIR)) -std=c++17
LIBNAME=libfrw

FRW_SOURCES=$(wildcard $(SDIR)/*.cpp)
FRW_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(FRW_SOURCES))

FRW_DEPS = $(patsubst %, %/*, $(IDIR)) 

FRW_DLIB_SOURCES= $(FRW_SOURCES)

build: build-dir $(FRW_OBJECTS) build-lib

build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)

$(FRW_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(FRW_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)

build-lib: $(FRW_OBJECTS)
	ar -crs $(LDIR)/$(LIBNAME).a $(FRW_OBJECTS) #build the static library
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(FRW_DLIB_SOURCES) $(CFLAGS)

install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	cp include/* /usr/local/include

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)