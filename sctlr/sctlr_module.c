#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read SCTLR_EL1 Register");

static int __init sctlr_init(void) {
    unsigned long sctlr;
    asm volatile ("mrs %0, SCTLR_EL1" : "=r" (sctlr));
    printk(KERN_INFO "SCTLR_EL1: %lx\n", sctlr);
    return 0;
}

static void __exit sctlr_exit(void) {
    printk(KERN_INFO "Exiting SCTLR Module\n");
}

module_init(sctlr_init);
module_exit(sctlr_exit);


