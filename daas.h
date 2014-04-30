#ifndef _DAAS_H
#define _DAAS_H

#define APPLICATION "daas"
#define NOTIFICATION_NAME "notify"
struct notify_item
{
	char name[32];
	void (*send)(char*);
};
int reg_notify(struct notify_item* iten);
EXPORT_SYMBOL(reg_notify);
#endif
