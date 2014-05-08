#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/vmalloc.h>
#define KILL_ERROR -1
#define REG_SUC     0
#define REG_UNSUC  -1
#define SUCCESS     0
#define APPLICATION_NAME "daas hardware manager"
#define DEVICE_NAME "sensor"
#define NOTIFICATION_MANAGER "nm"
struct notification_item
{
	char name[32];	
	void (*send)(void);
	void (*reset)(void);
	uint (*is_messageable)(void);
	void (*message)(char*);
};
int register_notification_item(struct notification_item*);
int hardware_open(struct inode *, struct file *);
int hardware_release(struct inode *, struct file *);
ssize_t hardware_read(struct file *, char *, size_t, loff_t *);
