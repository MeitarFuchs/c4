CC=gcc
FLAGS= -Wall -c

all:frequency

frequency: treeTrie.o main.o
		$(CC) -Wall -o frequency treeTrie.o main.o

treeTrie.o: treeTrie.c treeTrie.h
		$(CC) $(FLAGS) treeTrie.c
main.o: main.c
		$(CC) $(FLAGS) main.c treeTrie.c

.PHONY: clean all

clean:	
		rm -f *.o *.a a.out frequency