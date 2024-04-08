#include "../include/timer.h"

void start (timer* clk){
    clk->dragTime = 0;
    clk->isPaused = false;
    clk->pauseStart = 0;
}

void pause (timer* clk){
    if (!clk->isPaused){
        clk->isPaused = true;
        clk->pauseStart = clock ();
    }
}

void resume (timer* clk){
    if (clk->isPaused){
        clk->dragTime += clock () - clk->pauseStart;
        clk->isPaused = false;
        clk->pauseStart = 0;
    }
}

clock_t timestamp (timer* clk){
    return clock () - clk->dragTime;
}
