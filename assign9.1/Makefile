#-----------------------------------------------#
#  Makefile for unix systems                    #
#    using a GNU C compiler                     #
#-----------------------------------------------#
CC=gcc
CFLAGS=-O2 -g -Wall

all: hw9

hw9: hw9.c q1.o q2.o q3.o q4.o
	$(CC) $(CFLAGS) -o  hw9 hw9.c q1.o q2.o q3.o q4.o


q1.o:q1.c
	$(CC) $(CFLAGS) -c  q1.c

q2.o: q2.c
	$(CC) $(CFLAGS) -c  q2.c

q3.o:q3.c
	$(CC) $(CFLAGS) -c  q3.c

q4.o:q4.c
	$(CC) $(CFLAGS) -c  q4.c
clean:
	rm -f hw9 *.o

