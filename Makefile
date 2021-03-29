
OFILES = main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g -lgraph


main: main.c
	gcc main.c -o Blokus -lgraph


run:
	./Blokus

clean :
	-rm -f $(OFILES) Blokus

.PHONY : but clean