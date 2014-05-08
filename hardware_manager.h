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
struct notification_item
{
	void (*on)(void);
	void (*reset)(void);
	uint (*is_messageable)(void);
	void (*message)(cahr*);
};
