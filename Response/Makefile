CC=gcc
CPP=g++
IDIR=include ../Serializer/include ../FileReadWriter/include ../Request/include
ODIR=obj
LDIR=lib
SDIR=src
INCDIR=include
CFLAGS=$(patsubst %, -I%, $(IDIR)) -std=c++17
LIBNAME=libgoresponse

RESPONSE_SOURCES=$(wildcard $(SDIR)/*.cpp)
RESPONSE_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(RESPONSE_SOURCES))

RESPONSE_DLIB_SOURCES = $(RESPONSE_SOURCES)

RESPONSE_DEPS = $(patsubst %, %/*, $(IDIR)) 

RESPONSE_HEADERS = $(wildcard $(INCDIR)/*)
RESPONSE_UNINSTALL_HEADERS  = $(patsubst $(INCDIR)/%, %, $(RESPONSE_HEADERS)) 


$(RESPONSE_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/ftqproto/$@

.PHONY: $(RESPONSE_UNINSTALL_HEADERS) clean


build: build-dir $(RESPONSE_OBJECTS) build-lib



build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)

$(RESPONSE_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(RESPONSE_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)


build-lib: $(RESPONSE_DLIB_SOURCES) $(RESPONSE_DEPS)
	ar -crs $(LDIR)/$(LIBNAME).a $(RESPONSE_OBJECTS)
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(RESPONSE_DLIB_SOURCES) $(CFLAGS)
	
install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib
	
install-headers:
	cp include/* /usr/local/include/ftqproto

install-headers-docker:
	mv include/* /usr/include/ftqproto

uninstall: $(RESPONSE_UNINSTALL_HEADERS)
	rm -f /usr/local/lib/$(LIBNAME).so

install-docker:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib


clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)