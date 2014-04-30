#include <linux/completion.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include "daas.h"
int major;
static dev_t first;  
static struct cdev c_dev; 
static struct class *clss; 
int reg_notify(struct notify_item* item)
{
	return 0;	
}

static int __init constructor(void)
{
        printk(KERN_INFO "daas starting.....");
        if (alloc_chrdev_region(&first, 0, 1, APPLICATION) < 0)
        {
                return -1;
        }

        if ((clss = class_create(THIS_MODULE, NOTIFICATION_NAME)))
        {
                unregister_chrdev_region(first, 1);
                return -1;
        }

        if (device_create(clss, NULL, first, NULL, sensor->name))
        {
                class_destroy(cl);
                unregister_chrdev_region(first, 1);
                return -1;
        }

        cdev_init(&c_dev, &pugs_fops);

        if (cdev_add(&c_dev, first, 1) == -1)
        {
                device_destroy(cl, first);
                class_destroy(cl);
                unregister_chrdev_region(first, 1);
                return -1;
        }
	return 0;
}

static void __exit deconstructor(void)
{

}

module_init(constructor);
module_exit(deconstructor);
