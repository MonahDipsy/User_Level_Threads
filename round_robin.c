#include "thread.h"
#include "metrics.h"
#include "thread_logging.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/time.h>


// Round-robin signal handler
void RR_SignalHandler(int signum) {
    // Implement your Dispatch function here
}

void RR_Init(void) {
    // Set up the signal handler for round-robin
    struct sigaction sa;
    sa.sa_handler = RR_SignalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGVTALRM, &sa, NULL) == -1) {
        // Handle error
    }

    // Configure the timer (replace with appropriate value)
    struct itimerval timer;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 1000000; // Example time quantum
    timer.it_interval = timer.it_value;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        // Handle error
    }
}

void RunRoundRobinScheduling(void) {
    while (1) {
        // Implement your scheduling logic here
    }
}



