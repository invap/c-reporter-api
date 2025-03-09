// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/c-reporter-api.h"
#include "../include/stopwatch.h"

reporterPkg buffer[BUFFER_CAPACITY];
int buffer_used=0;

stopwatch reporting_clk;

void packAndSend(reporterPkg pkg, bool end_of_report){
    // Assume that the buffer always is not full
    if end_of_report {
        for (int i=BUFFER_USED; i<BUFFER_CAPACITY-1; i++ {
            buffer[buffer_used]=pkg;
            buffer_used++;
        }
    }
    buffer[buffer_used]=pkg;
    buffer_used++;
    // If the buffer is full, send it and mark as empty
    if (buffer_used==BUFFER_CAPACITY){
        fwrite(&buffer, sizeof(buffer), 1, stdout);
        fflush(stdout);
        buffer_used=0;
    }
}

void report (eventType event_type, char* event){
    reporterPkg pkg;
    pkg.time = getTime (&reporting_clk);
    pkg.event_type = event_type;
    switch (pkg.event_type){
        case timed_event: {
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case state_event:{
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case process_event:{
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case component_event: {
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case self_loggable_component_log_init_event:{
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case self_loggable_component_event: {
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case end_of_report_event: {
            sprintf(pkg.event, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        default:
            exit(1);
    }
    packAndSend(pkg);
}
