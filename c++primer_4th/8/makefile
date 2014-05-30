.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS= l8.3.get.cpp l8.4.cpp
$(BIN):$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
