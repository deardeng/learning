.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01socketpair 02send_fd
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

