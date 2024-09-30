// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#include "../include/stopwatch.h"

void start (stopwatch* clk){
    if (!clk->hasStarted) {
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
            clk->pauseStart = clock();
        } else
            exit(-2); // stopwatch was already paused
    } else
        exit(-1); // stopwatch not started
}

void resume (stopwatch* clk) {
    if (clk->hasStarted) {
        if (clk->isPaused) {
            clk->dragTime += clock() - clk->pauseStart;
            clk->isPaused = false;
            clk->pauseStart = 0;
        } else
            exit(-3); // stopwatch not in pause
    } else
        exit(-1); // stopwatch not started
}

clock_t getTime (stopwatch* clk){
    if (clk->hasStarted)
        if (clk->isPaused)
            return clk->pauseStart;
        else
            return clock () - clk->dragTime;
    else
        exit(-1); // stopwatch not started
}
