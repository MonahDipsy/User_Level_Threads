#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

// Define the maximum number of threads
#define MAX_NO_OF_THREADS 100

// Define the time quantum for round-robin scheduling (replace 1000000 with your desired value)
#define TIME_QUANTUM 1000000

// Function to initialize the round-robin scheduler
void RR_Init(void);

// Function to run the round-robin scheduling algorithm
void RunRoundRobinScheduling(void);

#endif // ROUND_ROBIN_H



