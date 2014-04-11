CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
EXEC=zadanie1.exe
all: $(EXEC)
$(EXEC): main.o list.o
	$(CC) main.o list.o -o $(EXEC)
main.o: main.c
	$(CC) $(CFLAGS) main.c
list.o: list.c
	$(CC) $(CFLAGS) list.c
clean:
	rm main.o list.o $(EXEC)
