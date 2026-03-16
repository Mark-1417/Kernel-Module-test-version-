#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void) {
	printk(KERN_INFO "Kernel module loading successful!\n");
	return 0;
}
static void __exit hello_exit(void) {
	printk(KERN_INFO "Kernel module unloading successful!\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("KM test");
MODULE_AUTHOR("1018");
