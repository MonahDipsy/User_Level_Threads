#ifndef THREAD_H
#define THREAD_H

#include <setjmp.h>
#include <sys/types.h>

// Define the maximum number of threads
#define MAX_NO_OF_THREADS 100

// Define thread states
enum ThreadState {
    THREAD_FREE,
    THREAD_READY,
    THREAD_RUNNING,
    THREAD_EXITED
};

// Define the thread structure
typedef struct {
    jmp_buf context;
    enum ThreadState state;
} Thread;

// Function to get a free thread index
int GetFreeThread(void);

// Function to run a thread
void RunThread(int tid);

// Function to exit a thread
void ExitThread(void);

// Function to yield a thread
void Yield(void);

// Function to get the thread ID
int GetMyID(void);

// Function to wake up a thread
void WakeUpOne(void);

#endif // THREAD_H



