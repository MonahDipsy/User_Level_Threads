CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = round_robin.o thread.o metrics.o thread_logging.o output.o

scheduling_algorithm: $(OBJS)
	$(CC) $(OBJS) -o scheduling_algorithm

round_robin.o: round_robin.c
	$(CC) $(CFLAGS) -c round_robin.c -o round_robin.o

lottery.o: lottery.c
	$(CC) $(CFLAGS) -c lottery.c -o lottery.o

thread.o: thread.c
	$(CC) $(CFLAGS) -c thread.c -o thread.o

metrics.o: metrics.c
	$(CC) $(CFLAGS) -c metrics.c -o metrics.o

thread_logging.o: thread_logging.c
	$(CC) $(CFLAGS) -c thread_logging.c -o thread_logging.o

output.o: output.c
	$(CC) $(CFLAGS) -c output.c -o output.o

clean:
	rm -f $(OBJS) scheduling_algorithm



