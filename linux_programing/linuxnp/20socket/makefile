.PHONY:clean all
CC=g++
CPPFLAGS=-Wall -g
BIN= 01chatsrv 02chatcli
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

