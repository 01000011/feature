#include <linux/completion.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>

#include <linux/vmalloc.h>
#include <asm/uaccess.h>
#include "hardware_manager.h"

static struct notification_item *no_item;
static dev_t devt;
static struct cdev c_dev;
static struct class *clss;

static struct file_operations fops = 
{
	.read = hardware_read,
	.open = hardware_open,
	.release = hardware_release
};

int hardware_open(struct inode *inode, struct file *file)
{
	return SUCCESS;
}

int hardware_release(struct inode *inode, struct file *file)
{
	return SUCCESS;
}

ssize_t hardware_read(struct file *file, char *buffer, size_t length, loff_t *offset)
{
	return 0;
        /*float *results = reginfo->sensor->read();
	put_user(*(results), buffer);	
	return sizeof(*results)*/
}

int register_notification_item(struct notification_item *noti_item)
{
	printk(KERN_INFO "Registering notification item '%s'", noti_item->name);
	if (device_create(clss, NULL, devt, NULL, noti_item->name) == NULL)
	{
		class_destroy(clss);
		unregister_chrdev_region(devt, 1);
		return -1;
	}
	cdev_init(&c_dev, &fops);
	c_dev.owner = THIS_MODULE;
	if (cdev_add(&c_dev, devt, 1) == -1)
	{
		device_destroy(clss, devt);
		class_destroy(clss);
		unregister_chrdev_region(devt, 1);
		return -1;
	}
	no_item = (struct notification_item*)vmalloc(sizeof(struct notification_item));
	no_item = noti_item;	
	return 0;	
}
EXPORT_SYMBOL(register_notification_item);

static int __init constructor(void)
{
        printk(KERN_INFO "Hardware manager start");
        if (alloc_chrdev_region(&devt, 0, 1, APPLICATION_NAME) < 0)
        {
                return -1;
        }

        if ((clss = class_create(THIS_MODULE, NOTIFICATION_MANAGER)) == NULL)
        {
                unregister_chrdev_region(devt, 1);
                return -1;
        }
        printk(KERN_INFO "Hardware manager complete");
        return 0;
}

static void __exit deconstructor(void)
{

}

module_init(constructor);
module_exit(deconstructor);
MODULE_LICENSE("GPL");
