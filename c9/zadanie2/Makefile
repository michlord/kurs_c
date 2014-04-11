CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
EXECUTABLE=zadanie2.exe
all: $(EXECUTABLE)
	cp $(EXECUTABLE) test/exe/$(EXECUTABLE)
$(EXECUTABLE): main.o
	$(CC) main.o -o $(EXECUTABLE)
main.o: main.c
	$(CC) $(CFLAGS) main.c
clean:
	rm main.o $(EXECUTABLE)