CC = g++
CFLAGS = -std=c++14 -g -O0 -masm=intel -fno-inline-small-functions
LIBS = -lncurses
SRC = main.cpp
EXENAME = predict.program

all: main.o trie.o
	$(CC) $(CFLAGS) main.o trie.o  $(LIBS) -o $(EXENAME) 

main.o: main.cpp
	$(CC) $(CFLAGS) -c $?

trie.o: trie.cpp
	$(CC) $(CFLAGS) -c $?

clean:
	rm -rf *.o *.program .*.swp
