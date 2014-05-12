.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS= 01tree.cpp
$(BIN):$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

