.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN= srv cli
all:$(BIN)
%.o:%.c
	$(CC) $(CPPFLAGS) -c $< -o $@
cli:cli.o sysutil.o
clean:
	rm -f *.o $(BIN)

