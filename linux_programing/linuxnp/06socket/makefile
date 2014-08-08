.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01byteorder 02addr
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

