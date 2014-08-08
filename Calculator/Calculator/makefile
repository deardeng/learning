.PHONY:clean
CC=g++
CPPFLAGS=-Wall -g
BIN= main
OBJS= main.cpp Calc.cpp Exception.cpp FunctionTable.cpp Node.cpp Parser.cpp Scanner.cpp Storage.cpp SymbolTable.cpp
$(BIN):$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

