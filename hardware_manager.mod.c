#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa60b9ee, "module_layout" },
	{ 0x12bee511, "cdev_init" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xe56368a0, "device_destroy" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x27e1a049, "printk" },
	{ 0x2c28632b, "device_create" },
	{ 0x3afdbb64, "cdev_add" },
	{ 0xc2a80510, "class_destroy" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x44e7643d, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D7643BA73D414F8B7051D5F");
