#include "c-reporter-api.h"

#include <stdio.h>
#include <string.h>

reporterPkg buffer[BUFFER_CAPACITY];
int buffer_used=0;

void packAndSend(reporterPkg pkg){
    // Assume that the buffer always is not full
    buffer[buffer_used]=pkg;
    buffer_used++;
    // If the buffer is full, send it and mark as empty
    if (buffer_used==BUFFER_CAPACITY){
        fwrite(&buffer, sizeof(buffer), 1, stdout);
        fflush(stdout);
        buffer_used=0;
    }
}

void report (clock_t time, eventType event_type, char* event){
    reporterPkg pkg;
    pkg.time = time;
    pkg.event_type = event_type;
    switch (pkg.event_type){
        case component_event: {
            sprintf(pkg.event.component_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case workflow_event:{
            sprintf(pkg.event.workflow_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        default:
            exit(1);
    }
    packAndSend(pkg);
}
