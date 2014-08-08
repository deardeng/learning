.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01signal 02signal
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

