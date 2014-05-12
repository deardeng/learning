.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN= main
OBJS= ex-1.o list.o set.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

