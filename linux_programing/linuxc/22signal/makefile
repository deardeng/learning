.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01setitimer 02setitimer 03setitimer
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

