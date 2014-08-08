.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01sigaction 02sigaction 03sigaction
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

