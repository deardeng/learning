.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01exec hello 03exec 04exec 05exec
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

