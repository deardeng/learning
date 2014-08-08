.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g
BIN = 01shm_open 02shm_unlink 03shm_write 04shm_read
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
01shm_open:01shm_open.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
02shm_unlink:02shm_unlink.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
03shm_write:03shm_write.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
04shm_read:04shm_read.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
clean:
	rm -f *.o $(BIN)
