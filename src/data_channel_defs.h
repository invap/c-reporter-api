#ifndef __DATA_CHANNEL_DEFS_H
#define __DATA_CHANNEL_DEFS_H

#define BUFFER_SIZE 65536 // 64K(os default) max string length to call (from the code) a test action (to be executed by the simulator)
#ifndef MAX_EVENT_SIZE
    #define MAX_EVENT_SIZE 119
#endif

#define MAX_EVENT_PKG_SIZE (MAX_EVENT_SIZE + 1 + 8)
#define BUFFER_CAPACITY (BUFFER_SIZE / MAX_EVENT_PKG_SIZE)

//Structure of component_event packages
typedef struct {
    char data[MAX_EVENT_SIZE + 1];
} componentEventPkg;

//Structure of workflow_event packages
typedef struct {
    char data[MAX_EVENT_SIZE + 1];
} workflowEventPkg;

//classification of the different types of events
typedef enum {component_event, workflow_event} eventType;

typedef struct {
    clock_t time;
    eventType event_type;
    union {
        componentEventPkg component_event_pkg;
        workflowEventPkg workflow_event_pkg;
    } event;
} reporterPkg;

#endif //__DATA_CHANNEL_DEFS_H
