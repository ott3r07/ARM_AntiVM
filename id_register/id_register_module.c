#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/sysreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read ID Register");

static int __init id_registers_init(void) {
    unsigned long id_aa64pfr0_el1, id_aa64mmfr0_el1;

    asm volatile("mrs %0, ID_AA64PFR0_EL1" : "=r" (id_aa64pfr0_el1));
    asm volatile("mrs %0, ID_AA64MMFR0_EL1" : "=r" (id_aa64mmfr0_el1));

    printk(KERN_INFO "ID_AA64PFR0_EL1: 0x%lx\n", id_aa64pfr0_el1);
    printk(KERN_INFO "ID_AA64MMFR0_EL1: 0x%lx\n", id_aa64mmfr0_el1);

    return 0;
}

static void __exit id_registers_exit(void) {
    printk(KERN_INFO "ID registers module unloaded\n");
}

module_init(id_registers_init);
module_exit(id_registers_exit);