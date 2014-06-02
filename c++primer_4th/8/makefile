.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS= l8.3.get.cpp l8.15.cpp
$(BIN):$(OBJS)
	$(CC) -std=c++11 $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) -std=c++11 $(CPPFLAGS) -c $< -o $@ 
clean:
	rm -f *.o $(BIN)
