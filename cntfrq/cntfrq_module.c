#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/sysreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read CNTFRQ_EL0 Register");

static int __init cntfrq_init(void) {
    unsigned long cntfrq_el0_value;

    asm volatile("mrs %0, cntfrq_el0" : "=r"(cntfrq_el0_value));
    printk(KERN_INFO "CNTFRQ_EL0: 0x%lx\n", cntfrq_el0_value);

    return 0;
}

static void __exit cntfrq_exit(void) {
    printk(KERN_INFO "cntfrq_module unloaded\n");
}

module_init(cntfrq_init);
module_exit(cntfrq_exit);
