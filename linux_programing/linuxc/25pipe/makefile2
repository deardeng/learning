.PHONY:clean
CC=gcc
CPPFLAGS=-Wall -g
BIN= 04fifow 05fifor
all:$(BIN)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

