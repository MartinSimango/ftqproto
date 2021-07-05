SUBDIRS=Request Response FileClient FileReadWriter FileServer  
SUBDIRS_CLEAN=$(patsubst %, %.clean, $(SUBDIRS))


.PHONY: $(SUBDIRS) $(SUBDIRS_CLEAN) clean

$(SUBDIRS): 
	$(MAKE) build install -C $(patsubst %,%, $@)

$(SUBDIRS_CLEAN):
	$(MAKE) clean -C $(patsubst %.clean,%, $@)

build: install-headers $(SUBDIRS)


bi-FileServer: bi-Response bi-Request
	$(MAKE) install-headers build install -C FileServer
bi-FileClient:
	$(MAKE) install-headers build install -C FileClient
bi-Request:
	$(MAKE) install-headers build install -C Request
bi-Response:
	$(MAKE) install-headers build install -C Response
bi-FileReadWriter:
	$(MAKE) install-headers build install -C FileReadWriter

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


uninstall:
	$(MAKE) uninstall -C FileServer
	$(MAKE) uninstall -C FileClient
	$(MAKE) uninstall -C Response
	$(MAKE) uninstall -C Request
	rm -rf /usr/local/include/ftqproto/Serializer.h 
	rm -rf /usr/local/include/ftqproto




clean: $(SUBDIRS_CLEAN)


