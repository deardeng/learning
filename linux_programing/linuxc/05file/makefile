.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01cp 02lseek 03hole 04ls
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

