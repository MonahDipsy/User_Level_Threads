#include "thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/time.h>

#define MAX_NO_OF_THREADS 100

typedef struct {
    jmp_buf context;
    int state;
} Thread;

#define THREAD_FREE     0
#define THREAD_READY    1
#define THREAD_RUNNING  2
#define THREAD_EXITED   3

Thread threads[MAX_NO_OF_THREADS];
int next_tid = 0;

int GetFreeThread() {
    for (int i = 0; i < MAX_NO_OF_THREADS; i++) {
        if (threads[i].state == THREAD_FREE) {
            return i;
        }
    }
    return -1;
}

void RunThread(int tid) {
    if (threads[tid].state != THREAD_READY) {
        return;
    }
    threads[tid].state = THREAD_RUNNING;
    siglongjmp(threads[tid].context, 1);
}

void ExitThread() {
    int tid = getpid() % MAX_NO_OF_THREADS;
    threads[tid].state = THREAD_EXITED;
}

void Yield() {
    int tid = getpid() % MAX_NO_OF_THREADS;
    threads[tid].state = THREAD_READY;
    siglongjmp(threads[tid].context, 1);
}

int GetMyID() {
    return getpid() % MAX_NO_OF_THREADS;
}

void WakeUpOne() {
    int tid = GetMyID();
    if (threads[tid].state == THREAD_READY) {
        threads[tid].state = THREAD_RUNNING;
        siglongjmp(threads[tid].context, 1);
    }
}

int main() {
    // Just a placeholder main function
    return 0;
}



