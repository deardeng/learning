.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01wait 02system
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

