.PHONY:clean 
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS= l5.21.cpp
$(BIN):$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

