.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN= main
OBJS= main.o process.o io.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

