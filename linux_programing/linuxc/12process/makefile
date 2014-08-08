.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 01fork 02fork 03vfork 04exit 05atexit 06fork 07fork 08exevce
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

