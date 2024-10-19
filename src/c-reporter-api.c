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

void report (eventType event_type, char* event){
    reporterPkg pkg;
    pkg.time = getTime (&reporting_clk);
    pkg.event_type = event_type;
    switch (pkg.event_type){
        case timed_event: {
            sprintf(pkg.event.timed_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case state_event:{
            sprintf(pkg.event.state_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case process_event:{
            sprintf(pkg.event.process_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case component_event: {
            sprintf(pkg.event.component_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case self_loggable_component_log_init_event:{
            sprintf(pkg.event.self_loggable_component_log_init_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        case self_loggable_component_event: {
            sprintf(pkg.event.self_loggable_component_event_pkg.data, "%-*s\n", MAX_EVENT_SIZE-2, event);
            break;
        }
        default:
            exit(1);
    }
    packAndSend(pkg);
}
