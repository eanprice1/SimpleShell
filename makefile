CC = gcc
CFLAGS = -g -c -I$(HEADERS)
OFLAGS = -g -o
SOURCE = source/
HEADERS = headers/

default: program

program: main.o inputHandler.o
	$(CC) $(OFLAGS) program main.o inputHandler.o
main.o: $(SOURCE)main.c $(HEADERS)inputHandler.h $(HEADERS)commandIndex.h
	$(CC) $(CFLAGS) $(SOURCE)main.c
inputHandler.o: $(SOURCE)inputHandler.c $(HEADERS)inputHandler.h $(HEADERS)commandIndex.h
	$(CC) $(CFLAGS) $(SOURCE)inputHandler.c

clean:
	$(RM) program *.o
run:
	./program