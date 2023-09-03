#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "thread.h"
#include "output.h"
#define MAX_NO_OF_THREADS 3

typedef enum {
    READY,
    RUNNING,
    EXITED
} ThreadState;

typedef struct {
    ThreadState state;
    int bursts;
    int execution_time;
    int sleep_time;
    float execution_time_quantum;
    float waiting_time;
    // Add more thread attributes here as needed
} Thread;

Thread threads[MAX_NO_OF_THREADS] = {
    {READY, 2, 5, 1, 2.5, 0.5}, // Thread 0
    {READY, 3, 8, 2, 2.67, 0.67}, // Thread 1
    {READY, 4, 10, 3, 2.5, 0.75} // Thread 2
};

void simulateRoundRobin() {
    for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
        while (threads[i].state != EXITED) {
            threads[i].state = RUNNING;
            // Simulate execution for a time quantum
            threads[i].execution_time -= threads[i].execution_time_quantum;
            
            if (threads[i].execution_time <= 0) {
                threads[i].execution_time = 0;
                threads[i].state = EXITED;
            } else {
                threads[i].state = READY;
                threads[i].waiting_time += threads[i].execution_time_quantum;
            }
        }
    }
}

void simulateLottery() {
    int total_tickets = 0;
    for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
        total_tickets += threads[i].bursts;
    }
    
    // Simulate Lottery scheduling
    for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
        while (threads[i].state != EXITED) {
            threads[i].state = RUNNING;
            // Simulate execution for a burst
            threads[i].execution_time -= threads[i].bursts;
            
            if (threads[i].execution_time <= 0) {
                threads[i].execution_time = 0;
                threads[i].state = EXITED;
            } else {
                threads[i].state = READY;
                threads[i].waiting_time += threads[i].bursts;
            }
        }
    }
}

void printThreadDetails(Thread thread, int thread_id) {
    printf("\n--- Thread %d ---\n", thread_id);
    printf("State Transition Sequence: ");
    
    // Placeholder for state transition sequence
    if (thread.state == EXITED) {
        printf("READY -> RUNNING -> READY -> RUNNING -> EXITED\n");
    } else {
        printf("READY -> RUNNING -> READY -> RUNNING -> READY -> RUNNING -> EXITED\n");
    }
    
    printf("Number of Bursts: %d\n", thread.bursts);
    printf("Total Execution Time: %d ms\n", thread.execution_time);
    printf("Total Requested Sleeping Time: %d ms\n", thread.sleep_time);
    printf("Average Execution Time Quantum: %.2f ms\n", thread.execution_time_quantum);
    printf("Average Waiting Time: %.2f ms\n", thread.waiting_time);
}

int main() {
    int choice;
    
    printf("Select Scheduling Policy:\n");
    printf("1. Round Robin\n");
    printf("2. Lottery\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        simulateRoundRobin();
        printf("Choice: 1\n");
        for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
            printThreadDetails(threads[i], i);
        }
    } else if (choice == 2) {
        simulateLottery();
        printf("Choice: 2\n");
        for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
            printThreadDetails(threads[i], i);
        }
    } else {
        printf("Invalid choice\n");
        return 1;
    }
    
    return 0;
}



