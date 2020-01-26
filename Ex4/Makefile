CC = gcc
CFLAGS = -g -Wall

all: main.o Trie.o frequency

frequency: main.o Trie.o
	$(CC) $(CFLAGS) main.o Trie.o -o frequency

main.o: main.c Trie.h
	$(CC) $(CFLAGS) -c main.c

Trie.o: Trie.c Trie.h
	$(CC) $(CFLAGS) -c Trie.c

clean:
	rm -f *o frequency
