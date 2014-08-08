.PHONY:clean all
CC = gcc
CFLAGS = -Wall -g
BIN = 01mq_open 02mq_unlink 03mq_getattr 04mq_send 05mq_recv 06mq_notify
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
01mq_open:01mq_open.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
02mq_unlink:02mq_unlink.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
03mq_getattr:03mq_getattr.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
04mq_send:04mq_send.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
05mq_recv:05mq_recv.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
06mq_notify:06mq_notify.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt
clean:
	rm -f *.o $(BIN)
