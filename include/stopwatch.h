#ifndef C_REPORTER_API_STOPWATCH_H
#define C_REPORTER_API_STOPWATCH_H

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    clock_t startTime;
    bool hasStarted;
    clock_t dragTime;
    bool isPaused;
    clock_t pauseStart;
} stopwatch;

void start (stopwatch*);
void pause (stopwatch*);
void resume (stopwatch*);
clock_t getTime (stopwatch*);

#endif //C_REPORTER_API_STOPWATCH_H
