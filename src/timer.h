#ifndef C_REPORTER_API_TIMER_H
#define C_REPORTER_API_TIMER_H

#include <time.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    clock_t dragTime;
    bool isPaused;
    clock_t pauseStart;
} timer;

void start (timer*);
void pause (timer*);
void resume (timer*);
clock_t timestamp (timer*);

#endif //C_REPORTER_API_TIMER_H
