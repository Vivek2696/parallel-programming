#include <iostream>
#include <cassert>
#include <pthread.h>
#include <cmath>
#include "../pthreads/helper.cpp"

int main(int argc, char *argv[]){
    if(argc < 3) {
        fprintf(stderr, "Must specify the size of the array and number of threads.\n");
        exit(1);
    }
    if(argc > 3) {
        srand(atoi(argv[3]));
    }

    unsigned array_size = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    thread_info_struct thread_info[num_threads];
    int* A = (int *)malloc(array_size * sizeof(int));
    assert(A != NULL);

    //TODO - Initialilze array

    //TODO - create thread to compute average by dividing into chunks

    //Join threads

    //To be continued...
    return 0;
}