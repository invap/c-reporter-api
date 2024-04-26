#ifndef __DATA_CHANNEL_DEFS_H
#define __DATA_CHANNEL_DEFS_H

#define BUFFER_SIZE 65536 // 64K(os default) max string length to call (from the code) a test action (to be executed by the simulator)
//  [ INSTRUMENTACION: Define el tamano del evento más largo reportado. ]
//  [ IMPORTANTE: 0 < __MAX_EVENT_SIZE <= 65528 ]
#define MAX_EVENT_SIZE (1022 + 2) // 308 is the longest event string plus 2 for the '\n'.
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

//Structure of workflow_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} workflowEventPkg;

//Structure of component_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} componentEventPkg;

//Structure of init_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} initEventPkg;

//Structure of component_event packages
typedef struct {
    char data[MAX_EVENT_SIZE];
} selfLoggableComponentEventPkg;

//classification of the different types of events
typedef enum {timed_event, state_event, workflow_event, component_event, init_event, self_loggable_component_event} eventType;

typedef struct {
    clock_t time;
    eventType event_type;
    union {
        timedEventPkg timed_event_pkg;
        stateEventPkg state_event_pkg;
        workflowEventPkg workflow_event_pkg;
        componentEventPkg component_event_pkg;
        selfLoggableComponentEventPkg self_loggable_component_event_pkg;
        initEventPkg init_event_pkg;
    } event;
} reporterPkg;

#endif //__DATA_CHANNEL_DEFS_H
