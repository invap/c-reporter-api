// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#ifndef __DATA_CHANNEL_DEFS_H
#define __DATA_CHANNEL_DEFS_H

#define BUFFER_SIZE 65536 // 64K(os default) max string length.
//  [ INSTRUMENTACION: Define el tamano del evento más largo reportado. ]
//  [ IMPORTANTE: 0 < MAX_EVENT_SIZE <= 65528 ]
#define MAX_EVENT_SIZE (1022 + 2)
//
#define MAX_EVENT_PKG_SIZE (MAX_EVENT_SIZE + 12)
#define BUFFER_CAPACITY (BUFFER_SIZE / MAX_EVENT_PKG_SIZE)

#include <time.h>

//Structure of timed_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} timedEventPkg;

//Structure of state_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} stateEventPkg;

//Structure of process_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} processEventPkg;

//Structure of component_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} componentEventPkg;

//Structure of self_loggable_component_log_init_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} selfLoggableComponentLogInitEventPkg;

//Structure of self_loggable_component_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} selfLoggableComponentEventPkg;

//classification of the different types of events
typedef enum {timed_event, state_event, process_event, component_event, self_loggable_component_log_init_event, self_loggable_component_event} eventType;

typedef struct {
    clock_t time;
    eventType event_type;
    union {
        timedEventPkg timed_event_pkg;
        stateEventPkg state_event_pkg;
        processEventPkg process_event_pkg;
        componentEventPkg component_event_pkg;
        selfLoggableComponentLogInitEventPkg self_loggable_component_log_init_event_pkg;
        selfLoggableComponentEventPkg self_loggable_component_event_pkg;
    } event;
} reporterPkg;

#endif //__DATA_CHANNEL_DEFS_H
