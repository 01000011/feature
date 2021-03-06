#define KILL_ERROR -1
#define REG_SUC     0
#define REG_UNSUC  -1
#define SUCCESS     0
#define APPLICATION_NAME "daas_hw_man"
#define DEVICE_NAME "sensor"
#define NOTIFICATION_MANAGER "notify_man"
struct notification_item
{
	char name[32];	
	void (*send)(void);
	void (*init)(void);
	uint (*is_messageable)(void);
	void (*message)(char*);
};
int register_notification_item(struct notification_item*);
int hardware_open(struct inode *, struct file *);
int hardware_release(struct inode *, struct file *);
ssize_t hardware_read(struct file *, char *, size_t, loff_t *);
