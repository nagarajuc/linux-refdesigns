DIRS=led_control hello blink toggle scroll_server scroll_client syschk write-bridge

all:
	@for subd in $(DIRS); do \
	$(MAKE) -C $$subd; \
	done

clean:
	@for subd in $(DIRS); do \
	$(MAKE) -C $$subd clean; \
	done
