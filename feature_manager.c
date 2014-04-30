#include <linux/kernel.h>
#include "feature_manager.h"
int reg_feature(struct feature_info* feature_info)
{
	printk(KERN_INFO "registering feature '%s'\n", feature_info->name);	
	
	return 0;
}	
