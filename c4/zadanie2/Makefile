CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
EXECUTABLE=program.exe
all: program.exe
$(EXECUTABLE): main.o fraction.o math_utils.o
	$(CC) main.o fraction.o math_utils.o -o $(EXECUTABLE)
main.o: main.c
	$(CC) $(CFLAGS) main.c
fraction.o: fraction.c
	$(CC) $(CFLAGS) fraction.c
math_utils.o: math_utils.c
	$(CC) $(CFLAGS) math_utils.c
clean:
	rm main.o fraction.o math_utils.o program.exe