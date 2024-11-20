// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#ifndef C_REPORTER_API_STOPWATCH_H
#define C_REPORTER_API_STOPWATCH_H

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ZERO,
    EPOCH
} basetime;

typedef struct {
    basetime zero;
    long startTime;
    bool hasStarted;
    long dragTime;
    bool isPaused;
    long pauseStart;
} stopwatch;

void start (stopwatch*, basetime bt);
void pause (stopwatch*);
void resume (stopwatch*);
long getTime (stopwatch*);

#endif //C_REPORTER_API_STOPWATCH_H
