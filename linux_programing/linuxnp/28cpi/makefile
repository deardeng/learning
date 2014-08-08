.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN=mmap_write mmap_read
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

