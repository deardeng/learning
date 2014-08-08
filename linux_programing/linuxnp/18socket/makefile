.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01echosrv 02echocli 01nofile_limit 02conntest 03pollsrv epollsrv
all:$(BIN)
%.o:%.c
	$(CC) $(CPPFLAGS) -c $< -o $@
%.o:%.cpp
	g++ $(CPPFLAGS) -c $< -o $@
epollsrv:epollsrv.o
	g++ $(CPPFLAGS)  $^ -o $@
clean:
	rm -f *.o $(BIN)

