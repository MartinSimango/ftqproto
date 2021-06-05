SUBDIRS=FileClient FileReadWriter FileServer Request Response
SUBDIRS_CLEAN=$(patsubst %, %.clean, $(SUBDIRS))


.PHONY: $(SUBDIRS) $(SUBDIRS_CLEAN) clean

$(SUBDIRS): 
	$(MAKE) build -C $(patsubst %,%, $@)

$(SUBDIRS_CLEAN):
	$(MAKE) clean -C $(patsubst %.clean,%, $@)

build: install-headers $(SUBDIRS)

build-docker: install-headers-docker $(SUBDIRS)

install: 
	$(MAKE) install -C FileServer
	$(MAKE) install -C FileClient
	$(MAKE) install -C Response
	$(MAKE) install -C Request
	$(MAKE) install -C FileReadWriter

install-headers:
	mkdir -p /usr/local/include/ftqproto
	$(MAKE) install-headers -C FileServer
	$(MAKE) install-headers -C FileClient
	$(MAKE) install-headers -C Response
	$(MAKE) install-headers -C Request
	$(MAKE) install-headers -C FileReadWriter
	cp Serializer/include/Serializer.h /usr/local/include/ftqproto


install-headers-docker:
	mkdir -p /usr/include/ftqproto
	$(MAKE) install-headers-docker -C FileServer
	$(MAKE) install-headers-docker -C FileClient
	$(MAKE) install-headers-docker -C Response
	$(MAKE) install-headers-docker -C Request
	$(MAKE) install-headers-docker -C FileReadWriter
	cp Serializer/include/Serializer.h /usr/include/ftqproto


uninstall:
	$(MAKE) uninstall -C FileServer
	$(MAKE) uninstall -C FileClient
	$(MAKE) uninstall -C Response
	$(MAKE) uninstall -C Request
	rm -rf /usr/local/include/ftqproto/Serializer.h 
	rm -rf /usr/local/include/ftqproto



install-docker: 
	mkdir -p /usr/include/ftqproto
	$(MAKE) install-docker -C FileServer
	$(MAKE) install-docker -C FileClient
	$(MAKE) install-docker -C Response
	$(MAKE) install-docker -C Request
	$(MAKE) install-docker -C FileReadWriter
	cp Serializer/include/Serializer.h /usr/include/ftqproto


clean: $(SUBDIRS_CLEAN)


gen-proto: 
