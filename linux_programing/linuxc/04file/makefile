.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= 01fileno 02open 03open 04open
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

