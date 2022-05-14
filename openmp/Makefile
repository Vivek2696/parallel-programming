# build tester.cpp and tree_depth.cpp

CC=g++
CFLAGS=-I. -fopenmp

all: find_depth

tester.o: tester.cpp tree_depth.o
	$(CC) -c -o tester.o $< $(CFLAGS)

tree_depth.o: tree_depth.cpp helper.o
	$(CC) -c -o tree_depth.o $< $(CFLAGS)

helper.o: helper.cpp
	$(CC) -c -o helper.o $< $(CFLAGS)

find_depth: tester.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o find_depth