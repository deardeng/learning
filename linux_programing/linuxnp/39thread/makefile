.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=pctest
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
threadattr:threadattr.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
pctest:pctest.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
clean:
	rm -f *.o $(BIN)

