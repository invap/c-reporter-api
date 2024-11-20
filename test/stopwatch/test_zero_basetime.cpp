// Copyright (c) 2024 Fundacion Sadosky, info@fundacionsadosky.org.ar
// Copyright (c) 2024 INVAP, open@invap.com.ar
// SPDX-License-Identifier: AGPL-3.0-or-later OR Fundacion-Sadosky-Commercial

#include <criterion/criterion.h>
#include <criterion/assert.h>
#define pause system_pause
#include <unistd.h>
#undef pause

extern "C" {
#include "../../include/stopwatch.h"
}

Test(Basetime_ZERO, test) {
    stopwatch clk;
    long time;
    start(&clk, ZERO);
    sleep(2);
    time = getTime(&clk);
    // Check that the code took a bit more than 2 seconds.
    cr_assert_eq (time/1000000, 2);
    sleep(3);
    time = getTime(&clk);
    // Check that the code took a bit more than 5 seconds.
    cr_assert_eq (time/1000000, 5);
    sleep(5);
    time = getTime(&clk);
    // Check that the code took a bit more than 10 seconds.
    cr_assert_eq (time/1000000, 10);
}

Test(Basetime_EPOCH, test) {
    stopwatch clk;
    long time;
    start(&clk, EPOCH);
    time = getTime(&clk);
    // Store the start time in seconds for later uso in checks.
    long start_time_in_sec = time/1000000;
    sleep(2);
    time = getTime(&clk);
    // Check that the code took a bit more than 2 seconds.
    cr_assert_eq ((time/1000000)-start_time_in_sec, 2);
    sleep(3);
    time = getTime(&clk);
    // Check that the code took a bit more than 5 seconds.
    cr_assert_eq ((time/1000000)-start_time_in_sec, 5);
    sleep(5);
    time = getTime(&clk);
    // Check that the code took a bit more than 10 seconds.
    cr_assert_eq ((time/1000000)-start_time_in_sec, 10);
}