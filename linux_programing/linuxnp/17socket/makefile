.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01echosrv 02echocli 01nofile_limit 02conntest 03pollsrv
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

