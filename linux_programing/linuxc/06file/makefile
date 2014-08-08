.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= 01stat
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

