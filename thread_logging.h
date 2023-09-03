#ifndef THREAD_LOGGING_H
#define THREAD_LOGGING_H

#include "thread.h" // Include any necessary headers for types used

// Initialize thread logging
void ThreadLogging_Init(void);

// Log a thread's state transition
void ThreadLogging_LogStateTransition(int thread_id, ThreadState old_state, ThreadState new_state);

// Clean up and close the log file
void ThreadLogging_Cleanup(void);

#endif // THREAD_LOGGING_H



