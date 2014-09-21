obj-m := pen_driver.o
CC=gcc
OBJ=test.c

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)

all: modules test.o

modules:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

test.o: $(OBJ)
	$(CC) -o $@ $<
	
.PHONY: clean
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *~ .*.cmd .tmp_*/
