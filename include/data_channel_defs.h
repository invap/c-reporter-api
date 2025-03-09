// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#ifndef __DATA_CHANNEL_DEFS_H
#define __DATA_CHANNEL_DEFS_H

#define BUFFER_SIZE 65536 // 64K(os default) max string length.
#define MAX_EVENT_SIZE (1010 + 2) // 1010: data, 2: string terminator
#define MAX_EVENT_PKG_SIZE (MAX_EVENT_SIZE + 12)  // MAX_EVENT_SIZE: event, 8: time, 4: event_type
#define BUFFER_CAPACITY (BUFFER_SIZE / MAX_EVENT_PKG_SIZE)

#include <time.h>

//Classification of the different types of events
typedef enum {
    timed_event,
    state_event,
    process_event,
    component_event,
    self_loggable_component_log_init_event,
    self_loggable_component_event,
    end_of_report_event
} eventType;

typedef struct {
    clock_t time;
    eventType event_type;
    char event[MAX_EVENT_SIZE];
} reporterPkg;


#endif //__DATA_CHANNEL_DEFS_H
