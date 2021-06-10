CC=gcc
CPP=g++
define IDIR
./include  ../Request/include ../Response/include ../FileReadWriter/include ../Serializer/include
endef
ODIR=obj
LDIR=lib
SDIR=src
INCDIR=include
CFLAGS=-std=c++17
LIBNAME=libgocpclient


CLIENT_SOURCES=$(wildcard $(SDIR)/*.cpp)
CLIENT_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CLIENT_SOURCES))

define CLIENT_DLIB_SOURCES
$(CLIENT_SOURCES) ../Request/src/*.cpp ../Response/src/*.cpp ../FileReadWriter/src/*.cpp 
endef

CLIENT_DEPS = $(wildcard $(IDIR)/*) 

CLIENT_HEADERS = $(wildcard $(INCDIR)/*)
CLIENT_UNINSTALL_HEADERS=$(patsubst $(INCDIR)/%, %, $(CLIENT_HEADERS)) 


.PHONY: $(CLIENT_UNINSTALL_HEADERS) clean

build: build-dir build-object-files build-lib

build-object-files: $(CLIENT_OBJECTS)

build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)

$(CLIENT_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(CLIENT_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)


build-lib: $(CLIENT_DLIB_SOURCES) $(CLIENT_DEPS)
	ar -crs $(LDIR)/$(LIBNAME).a $(CLIENT_OBJECTS)
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(CLIENT_DLIB_SOURCES) $(CFLAGS)

install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	
install-headers:
	cp include/* /usr/local/include/ftqproto


uninstall: $(CLIENT_UNINSTALL_HEADERS)
	rm -f /usr/local/lib/$(LIBNAME).so


$(CLIENT_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/ftqproto/$@

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)