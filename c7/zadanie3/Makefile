CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
EXECUTABLE=queue.exe
all: $(EXECUTABLE)
$(EXECUTABLE): main.o queue.o
	$(CC) main.o queue.o -o $(EXECUTABLE)
main.o: main.c
	$(CC) $(CFLAGS) main.c
queue.o: queue.c
	$(CC) $(CFLAGS) queue.c
clean:
	rm main.o queue.o $(EXECUTABLE)