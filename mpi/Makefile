# build reduce.cpp and main.cpp

CC=mpiCC
CFLAGS=-I.

all: test_reduce

main.o: main.cpp reduce.o
	$(CC) -c -o main.o $< $(CFLAGS)

reduce.o: reduce.cpp
	$(CC) -c -o reduce.o $< $(CFLAGS)

test_reduce: main.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o test_reduce
