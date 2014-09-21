obj-m := pen_driver.o
CC=gcc
OBJ=test.o

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
modules:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

test: $(OBJ)
	$(CC) -c -o $@ $^
	
.PHONY: clean
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *~ .*.cmd .tmp_*/
