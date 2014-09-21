obj-m := pen_driver.o

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
all:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

.PHONY: clean
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *~ .*.cmd .tmp_*/
