#include "thread.h"
#include "thread_logging.h"
#include <stdio.h>


// Structure representing a thread (as a placeholder)
typedef struct {
    int bursts;
    double execution_time;
    double sleep_time;
} Thread;

// Enum for thread states (as a placeholder)
typedef enum {
    THREAD_FREE,
    THREAD_READY,
    THREAD_RUNNING,
    THREAD_EXITED
} ThreadState;

// Function to convert thread state to string (as a placeholder)
const char *StateToString(ThreadState state) {
    switch (state) {
        case THREAD_FREE:   return "FREE";
        case THREAD_READY:  return "READY";
        case THREAD_RUNNING:return "RUNNING";
        case THREAD_EXITED: return "EXITED";
        default:            return "UNKNOWN";
    }
}

// Threads array (as a placeholder)
Thread threads[100];

// Log file pointer
static FILE *log_file;

// Initialize thread logging
void ThreadLogging_Init(void) {
    log_file = fopen("thread_log.txt", "w");
    if (!log_file) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "Thread ID\tState Transition\tBursts\tExecution Time (ms)\tSleep Time (ms)\n");
}

// Log a thread's state transition
void ThreadLogging_LogStateTransition(int thread_id, ThreadState old_state, ThreadState new_state) {
    fprintf(log_file, "%d\t%s -> %s\t%d\t%.2f\t%.2f\n",
            thread_id, StateToString(old_state), StateToString(new_state),
            threads[thread_id].bursts, threads[thread_id].execution_time / 1000.0,
            threads[thread_id].sleep_time / 1000.0);
}

// Clean up and close the log file
void ThreadLogging_Cleanup(void) {
    fclose(log_file);
}



