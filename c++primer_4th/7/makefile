.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS=l7.31.cpp l7.31.sales_item.cpp
$(BIN):$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

