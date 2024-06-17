#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/sysreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read CurrentEL Register");


static int __init el_init(void) {
    unsigned long current_el;

    asm volatile("mrs %0, CurrentEL" : "=r" (current_el));
    printk(KERN_INFO "CurrentEL: %lx\n", current_el >> 2);

    return 0;
}

static void __exit el_exit(void) {
    printk(KERN_INFO "CurrentEL module unloaded\n");
}

module_init(el_init);
module_exit(el_exit);