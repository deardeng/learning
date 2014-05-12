.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN= main
OBJS= l16.3.c
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

