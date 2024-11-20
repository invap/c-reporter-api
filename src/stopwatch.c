// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#include "../include/stopwatch.h"

void start (stopwatch* clk, basetime bt){
    if (!clk->hasStarted) {
        if (bt == ZERO){
            clk->zero = ZERO;
            /* The start time will serve to subtract to the current amount of
             * microseconds for getting the timestamp from 0.
             */
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            // Convert to microseconds
            clk->startTime = ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
        } else {
            /* The start time will serve to subtract to the current amount of
             * microseconds for getting the timestamp from epoch.
             */
            clk->zero = EPOCH;
            clk->startTime = 0;
        }
        clk->hasStarted = true;
        clk->dragTime = 0;
        clk->isPaused = false;
        clk->pauseStart = 0;
    } else
        exit(-4); // stopwatch already started
}

void pause (stopwatch* clk){
    if (clk->hasStarted) {
        if (!clk->isPaused) {
            clk->isPaused = true;
            /* The time at the moment of pause will serve to add to the
             * drag time at the moment the clock restarts.
             */
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            // Convert to microseconds
            clk->pauseStart = ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
        } else
            exit(-2); // stopwatch was already paused
    } else
        exit(-1); // stopwatch not started
}

void resume (stopwatch* clk) {
    if (clk->hasStarted) {
        if (clk->isPaused) {
            /* The time at the moment of resume will serve to compute
             * the amount of time add to the clock was paused to be added
             * to the drag time.
             */
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            // Convert to microseconds
            long pauseEnd = ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
            clk->dragTime += pauseEnd - clk->pauseStart;
            clk->isPaused = false;
            clk->pauseStart = 0;
        } else
            exit(-3); // stopwatch not in pause
    } else
        exit(-1); // stopwatch not started
}

long getTime (stopwatch* clk){
    if (clk->hasStarted)
        if (clk->isPaused)
            return clk->pauseStart - clk->startTime;
        else {
            /* The time is computed by subtracting clk->startTime to the
             * current time.
             */
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            // Convert to microseconds
            long time = ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
            return time - clk->startTime - clk->dragTime;
        }
    else
        exit(-1); // stopwatch not started
}
