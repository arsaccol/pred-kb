CC = g++
CFLAGS = -std=c++11
LIBS = -lncurses
SRC = main.cpp
EXENAME = predict.program

all:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(EXENAME)

clean:
	rm *.o *.program *.swp
