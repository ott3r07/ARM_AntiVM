#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x20c7250e, "proc_create" },
	{ 0x92997ed8, "_printk" },
	{ 0x82901638, "single_open" },
	{ 0x420ecd2a, "seq_printf" },
	{ 0xd5984a12, "remove_proc_entry" },
	{ 0x6c934406, "seq_read" },
	{ 0xa5a134ca, "seq_lseek" },
	{ 0x3a9c94d8, "single_release" },
	{ 0x8f80e6e5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EC11796F8284D88C320876C");
