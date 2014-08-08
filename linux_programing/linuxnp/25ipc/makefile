.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= msg_get
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

