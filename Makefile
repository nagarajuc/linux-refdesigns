DIRS=hello write-bridge read-bridge

all:
	@for subd in $(DIRS); do \
	$(MAKE) -C $$subd; \
	done

clean:
	@for subd in $(DIRS); do \
	$(MAKE) -C $$subd clean; \
	done
