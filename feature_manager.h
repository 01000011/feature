#include <linux/types.h>
struct feature_info
{
	char name[32];
	u8 id;
	void (*execute)(void);
	void (*execute_message)(char*);
};

int reg_feature(struct feature_info*);
