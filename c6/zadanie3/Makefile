CC=gcc
CFLAGS=-c -std=c99 -lm -Wall -Werror
QUICKTEST=quicktest.exe
VALIDITYTEST=testvalidity.exe
BENCHMARK=benchmark.exe
all: $(QUICKTEST) $(VALIDITYTEST) $(BENCHMARK)
$(BENCHMARK): benchmark.o randomsequence.o quicksort.o
	$(CC) benchmark.o randomsequence.o quicksort.o -o $(BENCHMARK)
$(QUICKTEST): quicktest.o sortvalidator.o randomsequence.o quicksort.o
	$(CC) quicktest.o sortvalidator.o randomsequence.o quicksort.o -o $(QUICKTEST)
$(VALIDITYTEST): validitytester.o sortvalidator.o randomsequence.o quicksort.o
	$(CC) validitytester.o sortvalidator.o randomsequence.o quicksort.o -o $(VALIDITYTEST)
quicktest.o: quicktest.c
	$(CC) $(CFLAGS) quicktest.c
sortvalidator.o: sortvalidator.c
	$(CC) $(CFLAGS) sortvalidator.c
randomsequence.o: randomsequence.c
	$(CC) $(CFLAGS) randomsequence.c
quicksort.o: quicksort.c
	$(CC) $(CFLAGS) quicksort.c
validitytester.o: validitytester.c
	$(CC) $(CFLAGS) validitytester.c
benchmark.o: benchmark.c
	$(CC) $(CFLAGS) benchmark.c
clean:
	rm benchmark.o quicktest.o sortvalidator.o randomsequence.o quicksort.o validitytester.o $(QUICKTEST) $(VALIDITYTEST) $(BENCHMARK)