.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN=sem semtool
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

