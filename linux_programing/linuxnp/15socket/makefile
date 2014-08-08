.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01echosrv 02echocli
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

