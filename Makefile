MAIN_DIR = src

.PHONY: main clean

all: main

main:
	$(MAKE) -C $(MAIN_DIR)

clean:
	$(MAKE) -C $(MAIN_DIR) clean

run-main:
	$(MAKE) -C $(MAIN_DIR) run
