SUBDIRS=FileClient FileReadWriter FileServer Request Response
SUBDIRS_CLEAN=$(patsubst %, %.clean, $(SUBDIRS))


.PHONY: $(SUBDIRS) $(SUBDIRS_CLEAN) clean

$(SUBDIRS): 
	$(MAKE) build -C $(patsubst %,%, $@)

$(SUBDIRS_CLEAN):
	$(MAKE) clean -C $(patsubst %.clean,%, $@)

build: $(SUBDIRS)


install: 
	$(MAKE) install -C FileServer
	$(MAKE) install -C FileClient
	$(MAKE) install -C Response
	$(MAKE) install -C Request

install-docker: 
	$(MAKE) install-docker -C FileServer
	$(MAKE) install-docker -C FileClient
	$(MAKE) install-docker -C Response
	$(MAKE) install-docker -C Request

clean: $(SUBDIRS_CLEAN)


