CC = gcc
CFLAGS = -g

default: program

program: main.o inputHandler.o
	$(CC) $(CFLAGS) -o program main.o inputHandler.o
main.o: main.c inputHandler.h
	$(CC) $(CFLAGS) -c main.c
inputHandler.o: inputHandler.c inputHandler.h
	$(CC) $(CFLAGS) -c inputHandler.c
clean:
	$(RM) program *.o
run:
	./program