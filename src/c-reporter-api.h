#ifndef __SIMULATOR_API
#define __SIMULATOR_API

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "data_channel_defs.h"

void packtAndSend(reporterPkg pkg);
void report (clock_t time, eventType event_type, char* event);

#endif //__SIMULATOR_API
