#ifndef __SIMULATOR_API
#define __SIMULATOR_API

#include <stdio.h>
#include <stdlib.h>

#include "timer.h"

#include "data_channel_defs.h"

void packtAndSend(reporterPkg pkg);
void report (eventType event_type, char* event);

#endif //__SIMULATOR_API
