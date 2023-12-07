#include "c-reporter-api.h"

#include <stdio.h>
#include <string.h>

reporterPkg buffer[BUFFER_CAPACITY];
int buffer_used=0;

void packAndSend(reporterPkg pkg){
    //assume that the buffer always is not full
    buffer[buffer_used]=pkg;
    buffer_used++;
    //if the bufferis full, send it and mark as empty //todo if we detect the end of write, we can complete the buffer wiht ignore packages
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
    char data[1024];
    sprintf(data, "%-*s\n", 1022, event);
    switch (pkg.event_type){
        case hardware_event: {
            hardwareEventPkg hardwareEvent;
            strcpy(hardwareEvent.data, data);
            pkg.event.hardware_event_pkg = hardwareEvent;
            break;
        }
        case workflow_event:{
            workflowEventPkg workflowEvent;
            strcpy(workflowEvent.data, data);
            pkg.event.workflow_event_pkg = workflowEvent;
            break;
        }
        default:
            exit(1);
    }
    packAndSend(pkg);
}
