#include <linux/kernel.h>
#include "feature_manager.h"
#define NOF 1
#define LED_TYPE 0x00
static feature_info features[NOF];
int has_type(struct feature_info*);
int reg_feature(struct feature_info* feature_info)
{
	printk(KERN_INFO "registering feature '%s'\n", feature_info->name);	
	if(has_type(feature_info) == -1)
	{
		return -1;
	}			
	return 0;
}
EXPORT_SYMBOL(reg_feature);
static int has_type(struct feature_info* feature_info)
{
	for(int i = 0; i < sizeof(*features); ++i)
	{
		if(features[i].type == feature_info.type)
		{
			return -1;
		}
	}
	return 0;
}

static int __init constructor(void)
{
        printk(KERN_INFO "Sensor manager start");
        if (alloc_chrdev_region(&devt, 0, 1, DEVICE_NAME) < 0)
        {
                return -1;
        }

        if ((clss = class_create(THIS_MODULE, CLASS)) == NULL)
        {
                unregister_chrdev_region(devt, 1);
                return -1;
        }
        printk(KERN_INFO "Sensor manager complete");
        return 0;
}

static void __exit deconstructor(void)
{
}
module_init(constructor);
module_exit(deconstructor);	
