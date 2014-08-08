.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=threadattr tsd
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
threadattr:threadattr.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
tsd:tsd.o
	$(CC) $(CFLAGS) $^ -o $@ -lpthread
clean:
	rm -f *.o $(BIN)

