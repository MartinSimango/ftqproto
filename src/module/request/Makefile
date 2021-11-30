CC=gcc
CPP=g++
IDIR=include ../Serializer/include ../FileReadWriter/include
ODIR=obj
LDIR=lib
SDIR=src
INCDIR=include
CFLAGS=-std=c++17 -lprotobuf
LIBNAME=libgorequest

REQUEST_SOURCES=$(wildcard $(SDIR)/*.cpp)
REQUEST_PROTO_SOURCES=$(wildcard gen/ftqproto/*.cc)
REQUEST_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(REQUEST_SOURCES))

REQUEST_DLIB_SOURCES = $(REQUEST_SOURCES)

REQUEST_DEPS = $(wildcard $(IDIR)/*) 

REQUEST_HEADERS = $(wildcard $(INCDIR)/*)
REQUEST_UNINSTALL_HEADERS = $(patsubst $(INCDIR)/%, %, $(REQUEST_HEADERS)) 
REQUEST_UNINSTALL_PROTO_HEADERS=$(patsubst $(INCDIR)/%, %, $(REQUEST_HEADERS)) 


.PHONY: $(REQUEST_UNINSTALL_HEADERS) $(REQUEST_OBJECTS) clean 

install-headers: install-proto-headers gen-proto install-gen-headers
	cp include/* /usr/local/include/ftqproto

install-proto-headers:
	cp proto/* /usr/local/include/ftqproto

build: build-dir build-object-files build-lib 

build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)	

build-object-files: $(REQUEST_OBJECTS)


# todo account for proto source files
$(REQUEST_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(REQUEST_DEPS) 
	$(CPP) -c $< -o $@ $(CFLAGS)


build-lib: $(REQUEST_DLIB_SOURCES) $(REQUEST_DEPS)
	ar -crs $(LDIR)/$(LIBNAME).a $(REQUEST_OBJECTS)
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(REQUEST_DLIB_SOURCES) $(REQUEST_PROTO_SOURCES) $(CFLAGS)

gen-proto: proto
	mkdir -p gen
	protoc  \
	--cpp_out=gen \
	ftqproto/CreateRequest.proto \
	ftqproto/GetRequest.proto \
	ftqproto/ReadRequest.proto \
	ftqproto/WriteRequest.proto \
	ftqproto/RequestFile.proto \
	
	
install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib


uninstall: $(REQUEST_UNINSTALL_HEADERS) uninstall-gen-headers
	rm -f /usr/local/lib/$(LIBNAME).so

$(REQUEST_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/ftqproto/$@

uninstall-gen-headers:
	rm -f /usr/local/include/ftqproto/CreateRequest.pb.h
	rm -f /usr/local/include/ftqproto/GetRequest.pb.h
	rm -f /usr/local/include/ftqproto/WriteRequest.pb.h
	rm -f /usr/local/include/ftqproto/ReadRequest.pb.h
	rm -f /usr/local/include/ftqproto/RequestFile.pb.h

install-gen-headers:
	cp gen/ftqproto/*.h /usr/local/include/ftqproto

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)
	rm -rf gen
