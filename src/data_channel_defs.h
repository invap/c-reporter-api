#ifndef SIMULADOR_DATA_CHANNEL_DEFS_H
#define SIMULADOR_DATA_CHANNEL_DEFS_H

#define BUFFER_SIZE 65536 // 64K(os default) max string length to call (from the code) a test action (to be executed by the simulator)
#define MAX_BUFFER_SIZE 1036
#define BUFFER_CAPACITY BUFFER_SIZE / MAX_BUFFER_SIZE

//Structure of hardware_event packages
typedef struct {
    char data[1024];
} hardwareEventPkg;

//Structure of workflow_event packages
typedef struct {
    char data[1024];
} workflowEventPkg;

//classification of the different types of events
typedef enum {hardware_event, workflow_event} eventType;

typedef struct {
    clock_t time;
    eventType event_type;
    union {
        hardwareEventPkg hardware_event_pkg;
        workflowEventPkg workflow_event_pkg;
    } event;
} reporterPkg;

#endif //SIMULADOR_DATA_CHANNEL_DEFS_H
