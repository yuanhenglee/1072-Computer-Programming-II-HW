CC=gcc
CFLAGS=-O2 -g -Wall

all: hw5

hw5: hw5.o queue.o stack.o mystruct.o list.o
	$(CC) $(CFLAGS) -o  hw5 hw5.o stack.o queue.o mystruct.o list.o

hw5.o: hw5.c
	$(CC) $(CFLAGS) -c  hw5.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c  queue.c

mystruct.o: mystruct.c mystruct.h
	$(CC) $(CFLAGS) -c  mystruct.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c  stack.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c  list.c
clean:
	rm -f hw5 *.o

