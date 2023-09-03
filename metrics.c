#include "thread.h"
#include "metrics.h"
#include <stdio.h>


// Define the number of threads
#define NUM_THREADS 3

// Define the thread structure
struct Thread {
    int execution_time;
    int bursts;
    int total_waiting_time;
};

// Define an array of threads and initialize it
struct Thread threads[NUM_THREADS] = {
    {1000, 5, 2000}, // Thread 0
    {1500, 4, 2500}, // Thread 1
    {800, 3, 1500}   // Thread 2
};

// Define the number of threads
int num_threads = NUM_THREADS;

void CalculateAndPrintMetrics(void) {
    printf("Thread Metrics:\n");
    printf("Thread ID\tAverage Execution Time (ms)\tAverage Waiting Time (ms)\n");

    for (int i = 0; i < num_threads; i++) {
        double avg_exec_time = (threads[i].execution_time / 1000.0) / threads[i].bursts;
        double avg_waiting_time = (threads[i].total_waiting_time / 1000.0) / threads[i].bursts;

        printf("%d\t\t%.2f\t\t\t%.2f\n", i, avg_exec_time, avg_waiting_time);
    }
}



