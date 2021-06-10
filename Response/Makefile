CC=gcc
CPP=g++
IDIR=include ../Serializer/include ../FileReadWriter/include ../Request/include
ODIR=obj
LDIR=lib
SDIR=src
INCDIR=include
CFLAGS=-std=c++17 -lgorequest -lprotobuf
LIBNAME=libgoresponse

RESPONSE_SOURCES=$(wildcard $(SDIR)/*.cpp)
RESPONSE_PROTO_SOURCES=$(wildcard gen/ftqproto/*.cc)
RESPONSE_OBJECTS=$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(RESPONSE_SOURCES))

RESPONSE_DLIB_SOURCES = $(RESPONSE_SOURCES)

RESPONSE_DEPS = $(wildcard $(IDIR)/*) 

RESPONSE_HEADERS = $(wildcard $(INCDIR)/*)
RESPONSE_UNINSTALL_HEADERS = $(patsubst $(INCDIR)/%, %, $(RESPONSE_HEADERS)) 


$(RESPONSE_UNINSTALL_HEADERS):
	rm -rf /usr/local/include/ftqproto/$@

.PHONY: $(RESPONSE_UNINSTALL_HEADERS) clean


install-headers: install-proto-headers gen-proto install-gen-headers
	cp include/* /usr/local/include/ftqproto

install-proto-headers:
	cp proto/* /usr/local/include/ftqproto

build: build-dir build-object-files build-lib 


build-dir:
	mkdir -p $(ODIR)
	mkdir -p $(LDIR)	

build-object-files: $(RESPONSE_OBJECTS)

$(RESPONSE_OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp $(RESPONSE_DEPS)
	$(CPP) -c $< -o $@ $(CFLAGS)


build-lib: $(RESPONSE_DLIB_SOURCES) $(RESPONSE_DEPS)
	ar -crs $(LDIR)/$(LIBNAME).a $(RESPONSE_OBJECTS)
	$(CPP) -shared -fPIC -o $(LDIR)/$(LIBNAME).so $(RESPONSE_DLIB_SOURCES) $(RESPONSE_PROTO_SOURCES) $(CFLAGS)

gen-proto: proto
	mkdir -p gen
	protoc  \
	-I=/usr/local/include/ \
	--cpp_out=gen \
	ftqproto/CreateResponse.proto \
	ftqproto/GetResponse.proto \
	ftqproto/ReadResponse.proto \
	ftqproto/WriteResponse.proto \
	
	
install:
	rm -f /usr/local/lib/$(LIBNAME).so
	cp $(LDIR)/$(LIBNAME).so /usr/local/lib


uninstall: $(RESPONSE_UNINSTALL_HEADERS) uninstall-gen-headers
	rm -f /usr/local/lib/$(LIBNAME).so

uninstall-gen-headers:
	rm -f /usr/local/include/ftqproto/CreateResponse.pb.h
	rm -f /usr/local/include/ftqproto/GetResponse.pb.h
	rm -f /usr/local/include/ftqproto/WriteResponse.pb.h
	rm -f /usr/local/include/ftqproto/ReadResponse.pb.h

install-gen-headers:
	cp gen/ftqproto/*.h /usr/local/include/ftqproto

clean:
	rm -rf $(ODIR)
	rm -rf $(LDIR)
	rm -rf gen