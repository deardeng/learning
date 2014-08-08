.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= dining
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

