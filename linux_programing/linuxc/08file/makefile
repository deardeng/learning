.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01fcntl 02fcntl 03fcntl
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

