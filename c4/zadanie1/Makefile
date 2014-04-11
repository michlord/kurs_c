CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
EXECUTABLE=program.exe
all: program.exe
$(EXECUTABLE): main.o set.o
	$(CC) main.o set.o -o $(EXECUTABLE)
main.o: main.c
	$(CC) $(CFLAGS) main.c
set.o: set.c
	$(CC) $(CFLAGS) set.c
clean:
	rm main.o set.o program.exe