CC=g++
CFLAGS=-I. -pthread

all: compute_avg

compute_avg: compute_avg.o
	$(CC) -o $@ $^ $(CFLAGS)

compute_avg.o: compute_avg.cpp helper.o
	$(CC) $(CFLAGS) -c -o compute_avg.o $<

helper.o: helper.cpp
	$(CC) $(CFLAGS) -c -o helper.o $<

clean:
	rm -f *.o compute_avg