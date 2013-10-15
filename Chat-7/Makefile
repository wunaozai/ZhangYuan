obj-m :=mymodule.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)

clean:
	rm -rf *.o *.ko *.mod.o *.mod.c *.symvers *.order *.ko.unsigned
