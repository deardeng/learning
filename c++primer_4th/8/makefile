.PHONY:clean
CC=g++
CPPFLAGS=-Wall -gdwarf-2
BIN= main
OBJS= l8.3.get.cpp l8.14.cpp
$(BIN):$(OBJS)
	$(CC) -std=c++11 $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) -std=c++11 $(CPPFLAGS) -c $< -o $@ 
clean:
	rm -f *.o $(BIN)
