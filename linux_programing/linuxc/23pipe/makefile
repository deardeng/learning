.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01pipe 02pipe 03cp
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

