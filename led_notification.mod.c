#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
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
	{ 0x5f49e25f, __VMLINUX_SYMBOL_STR(register_notification_item) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=hardware_manager";


MODULE_INFO(srcversion, "923A3A51C99D0EF6AE8E546");
