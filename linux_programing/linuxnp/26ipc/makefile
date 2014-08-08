.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= msg_get msg_send msg_recv
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

