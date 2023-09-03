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


struct LotteryThread lottery_threads[MAX_NO_OF_THREADS];
int num_lottery_threads = 0;

void InitializeLotteryScheduler() {
	num_lottery_threads = 0;
	srand(time(NULL));
}

void AddThreadToLottery(int thread_id, int tickets) {
	if (num_lottery_threads < MAX_NO_OF_THREADS) {
    	struct LotteryThread new_thread;
    	new_thread.thread_id = thread_id;
    	new_thread.tickets = tickets;
    	lottery_threads[num_lottery_threads++] = new_thread;
	} else {
    	// Handle error: Max threads reached
	}
}

int ChooseWinner() {
	int total_tickets = 0;
	for (int i = 0; i < num_lottery_threads; i++) {
    	total_tickets += lottery_threads[i].tickets;
	}
    
	int winning_ticket = rand() % total_tickets;
    
	int sum_tickets = 0;
	for (int i = 0; i < num_lottery_threads; i++) {
    	sum_tickets += lottery_threads[i].tickets;
    	if (winning_ticket < sum_tickets) {
        	return lottery_threads[i].thread_id;
    	}
	}
    
	// Handle error: No winner found
	return -1;
}

void LotteryDispatch(int sig) {
	int winner = ChooseWinner();
	// Switch to the thread with the chosen winner
	// Actual context switching code here
}

void CleanUpLotteryScheduler() {
	// Clean up data structures and resources
}



