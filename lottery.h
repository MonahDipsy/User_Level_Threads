#ifndef LOTTERY_H
#define LOTTERY_H

#define MAX_NO_OF_THREADS 100 // Define your maximum number of threads here

struct LotteryThread {
	int thread_id;
	int tickets;
};

void InitializeLotteryScheduler();
void AddThreadToLottery(int thread_id, int tickets);
int ChooseWinner();
void LotteryDispatch(int sig);
void CleanUpLotteryScheduler();

#endif



