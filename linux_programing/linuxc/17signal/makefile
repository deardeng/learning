.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01kill 02kill 03pause
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

