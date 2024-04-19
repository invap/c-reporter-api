#include "../include/stopwatch.h"

void start (stopwatch* clk){
    if (!clk->hasStarted) {
        clk->startTime = clock();
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

void reset (stopwatch* clk){
    if (clk->hasStarted) {
        clk->hasStarted = false;
        clk->startTime = clock();
        clk->dragTime = 0;
        clk->isPaused = false;
        clk->pauseStart = 0;
    } else
        exit(-1); // stopwatch not started
}

clock_t getTime (stopwatch* clk){
    if (clk->hasStarted)
        return clock () - clk->startTime - clk->dragTime;
    else
        exit(-1); // stopwatch not started
}
