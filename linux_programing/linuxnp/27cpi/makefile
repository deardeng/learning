.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN=echosrv echocli
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

