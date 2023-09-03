#include "output.h"
#include <stdio.h>

// Define the maximum number of threads
#define MAX_NO_OF_THREADS 100
#define MAX_TRANSITIONS 100

// Define thread states
#define READY 0
#define RUNNING 1
#define SLEEPING 2

// Define the thread structure
struct Thread {
    int id;
    int bursts;
    int execution_time;
    int sleep_time;
    int execution_time_quantum;
    int state_transition_count;
    int state_transitions[MAX_TRANSITIONS];
    int waiting_time;
};

// Array of thread structures
struct Thread threads[MAX_NO_OF_THREADS];
int num_threads = 0;

// Convert thread state to string representation
const char* StateToString(int state) {
    switch (state) {
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case SLEEPING: return "SLEEPING";
        default: return "UNKNOWN";
    }
}

// Print the state transition sequence for a thread
void PrintThreadStateTransition(int thread_id) {
    struct Thread *thread = &threads[thread_id];
    
    printf("Thread ID: %d\n", thread_id);
    printf("State Transition Sequence: ");
    
    for (int i = 0; i < thread->state_transition_count; i++) {
        printf("%s", StateToString(thread->state_transitions[i]));
        
        if (i != thread->state_transition_count - 1) {
            printf(" -> ");
        }
    }
    
    printf("\n\n");
}

// Print thread metrics
void PrintThreadMetrics(int thread_id) {
    struct Thread *thread = &threads[thread_id];
    
    printf("Thread ID: %d\n", thread_id);
    printf("Number of Bursts: %d\n", thread->bursts);
    printf("Total Execution Time (ms): %.2f\n", thread->execution_time / 1000.0);
    printf("Total Requested Sleeping Time (ms): %.2f\n", thread->sleep_time / 1000.0);
    printf("Average Execution Time Quantum (ms): %.2f\n", thread->execution_time_quantum / 1000.0);
    printf("Average Waiting Time (status = READY) (ms): %.2f\n", thread->waiting_time / 1000.0);
    printf("\n");
}

// Print the demonstration of round robin and lottery scheduling
void PrintSchedulingDemonstration(void) {
    printf("Demonstration of Round Robin and Lottery Scheduling:\n");
    
    // Print thread state transitions and metrics
    for (int i = 0; i < num_threads; i++) {
        PrintThreadStateTransition(i);
        PrintThreadMetrics(i);
    }
}



