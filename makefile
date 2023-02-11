CC = gcc
CFLAGS = -g -c -I$(HEADERS)
OFLAGS = -g -o
SOURCE = source/
HEADERS = headers/

default: program

program: main.o inputHandler.o commandIndex.o pipe.o
	$(CC) $(OFLAGS) program main.o inputHandler.o commandIndex.o pipe.o
main.o: $(SOURCE)main.c $(HEADERS)inputHandler.h $(HEADERS)commandIndex.h
	$(CC) $(CFLAGS) $(SOURCE)main.c
inputHandler.o: $(SOURCE)inputHandler.c $(HEADERS)inputHandler.h $(HEADERS)commandIndex.h
	$(CC) $(CFLAGS) $(SOURCE)inputHandler.c
commandIndex.o: $(SOURCE)commandIndex.c $(HEADERS)commandIndex.h
	$(CC) $(CFLAGS) $(SOURCE)commandIndex.c
pipe.o: $(SOURCE)pipe.c $(HEADERS)pipe.h
	$(CC) $(CFLAGS) $(SOURCE)pipe.c
clean:
	$(RM) program *.o
run:
	./program