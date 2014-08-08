.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01testd
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

