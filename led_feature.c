#include <asm/io.h>
#include <linux/ioport.h>
#include <linux/module.h>	
#include <linux/kernel.h>	
#include <linux/init.h>	
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include "led_feature.h"
#define GPIO1_START       0x4804C000
#define GPIO1_END         0x4804CFFF
#define GPIO_SETDATAOUT   GPIO1_START | 0x194
#define GPIO_CLEARDATAOUT GPIO1_START | 0x190 
#define GPIO_OE           GPIO1_START | 0x134
#define GPIO_DATAIN       GPIO1_START | 0x138
#define BITS              32
#define GPIO14            0x00004000

MODULE_AUTHOR("Courtney Harleston");
MODULE_DESCRIPTION("enables a light");
MODULE_LICENSE("Proprietary");
static struct feature_info feature_dev = 
{
	.name = "led",
	.execute = execute,
	.execute_message = execute_message
};

static void execute(void)
{
	unsigned int value;
        volatile void *gpio_setdataout;
        volatile void *gpio_oe;
        volatile void *gpio_datain;

        printk(KERN_INFO "start gpio\n");
        if(!request_mem_region(GPIO1_START, GPIO1_END - GPIO1_START, "me"))
        {
                gpio_oe = ioremap(GPIO_OE, BITS);
                gpio_setdataout = ioremap(GPIO_SETDATAOUT, BITS);
                gpio_datain = ioremap(GPIO_DATAIN, BITS);
                value = read_mem(gpio_datain);
                printk(KERN_INFO "addr=%p, value=%u\n", gpio_datain, value);
                write_to_mem(gpio_oe, 0x0);
                write_to_mem(gpio_setdataout, GPIO14);

                value = read_mem(gpio_datain);
                printk(KERN_INFO "addr=%p, value=%u\n", gpio_datain, value);
                iounmap(gpio_oe);
                iounmap(gpio_setdataout);
                iounmap(gpio_datain);
        }
	
}

static void execute_message(char* message)
{

}

void write_to_mem(volatile const void* addr, const unsigned int value)
{
	iowrite32(value, (void*)addr);
}

unsigned int read_mem(volatile void* addr)
{
	return ioread32((void*)addr);
}

static int __init constructor(void)
{
	reg_feature(&feature_dev);
	return 0;
}

static void __exit destructor(void)
{
	volatile void *gpio_cleardataout;
	gpio_cleardataout = ioremap(GPIO_CLEARDATAOUT, BITS);
	write_to_mem(gpio_cleardataout, GPIO14);
	iounmap(gpio_cleardataout);
	release_mem_region(GPIO1_START, GPIO1_END - GPIO1_START);
}

module_init(constructor);
module_exit(destructor);
