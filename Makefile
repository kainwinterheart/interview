TARGET = all

MAKEFILE_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SRC_DIR := $(MAKEFILE_DIR)/src

all: logs res1 res2
	echo done

clean:
	find $(SRC_DIR) -name '*.o' -exec rm {} \;

clean-all:
	find $(MAKEFILE_DIR) -name '*.o' -exec rm {} \;

logs:
	$(MAKE) -C $(SRC_DIR)/logs

res1:
	$(MAKE) -C $(SRC_DIR)/res1

res2:
	$(MAKE) -C $(SRC_DIR)/res2
