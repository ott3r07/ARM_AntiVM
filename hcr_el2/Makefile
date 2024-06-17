obj-m += hyp_mode_module.o
ARCH = arm64
CROSS_COMPILE = aarch64-linux-gnu-
KERNEL_DIR = /home/exp/arm_anti_vm/ARM_AntiVM/test_code/linux-headers-6.1.21-v8+

all:
	LD_LIBRARY_PATH=/usr/aarch64-linux-gnu/lib:$(LD_LIBRARY_PATH)
	make -C $(KERNEL_DIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) clean

