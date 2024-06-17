#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/sysreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read MIDR_EL1 Register");


static int __init midr_init(void) {
    unsigned long midr_el1;

    asm volatile("mrs %0, MIDR_EL1" : "=r" (midr_el1));
    printk(KERN_INFO "MIDR_EL1: 0x%lx\n", midr_el1);

    return 0;
}

static void __exit midr_exit(void) {
    printk(KERN_INFO "MIDR_EL1 module unloaded\n");
}

module_init(midr_init);
module_exit(midr_exit);