.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01echosrv 02echocli  03echosrv 04p2psrv 05p2pcli
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

