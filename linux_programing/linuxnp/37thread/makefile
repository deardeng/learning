.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g
BIN = 01thread echosrv echocli
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
01thread:01thread.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
echosrv:echosrv.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
clean:
	rm -f *.o $(BIN)
