#include "feature_manager.h"
static void execute(void);
static void execute_message(char*);
void write_to_mem(volatile const void*, const unsigned int);
unsigned int read_mem(volatile void*);
