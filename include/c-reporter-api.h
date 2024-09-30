// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#ifndef __SIMULATOR_API
#define __SIMULATOR_API

#include "data_channel_defs.h"

void packtAndSend(reporterPkg pkg);
void report (eventType event_type, char* event);

#endif //__SIMULATOR_API
