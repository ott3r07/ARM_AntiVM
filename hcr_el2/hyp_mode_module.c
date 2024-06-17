#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/sysreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ott3r");
MODULE_DESCRIPTION("Read hcr Register");

static int hcr_show(struct seq_file *m, void *v) {
    unsigned long hcr_el2;

    asm volatile("mrs %0, hcr_el2" : "=r" (hcr_el2));
    seq_printf(m, "HCR_EL2: %lx\n", hcr_el2);

    return 0;
}

static int hcr_open(struct inode *inode, struct file *file) {
    return single_open(file, hcr_show, NULL);
}

static const struct proc_ops hcr_ops = {
    .proc_open = hcr_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int __init hcr_init(void) {
    proc_create("hcr_el2", 0, NULL, &hcr_ops);
    printk(KERN_INFO "HCR_EL2 module loaded\n");
    return 0;
}

static void __exit hcr_exit(void) {
    remove_proc_entry("hcr_el2", NULL);
    printk(KERN_INFO "HCR_EL2 module unloaded\n");
}

module_init(hcr_init);
module_exit(hcr_exit);
