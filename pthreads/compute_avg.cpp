#include <iostream>
#include <cassert>
#include <pthread.h>
#include <cmath>
#include "../pthreads/helper.cpp"

void* partial_sum(void *my_info)
{
    thread_info_struct *info = (thread_info_struct *)my_info;
    //fprintf(stdout, "thread %d executing %d-%d\n", info->num, info->start, info->end);
    for (int i = info->start; i < info->end; i++)
    {
        info->partial_sum += info->array[i];
    }
    return (void*)&(info->partial_sum);
}

double seq_average(int *A, int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += A[i];
    }
    return (double)sum / len;
}

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

    for(int i = 0; i < array_size; i++){
        A[i] = rand() % 1000;
    }
    double average = 0;
    int *local_sum = (int *)malloc(num_threads * sizeof(int));
    assert(local_sum != NULL);

    for(int i = 0; i < num_threads; i++){
        thread_info[i].num = i;
        double base = round((double) array_size / num_threads);
        thread_info[i].start = (int)(base * i);
        thread_info[i].end = (int)(base * (i+1));
        if (thread_info[i].end > array_size){
            thread_info[i].end = array_size;
        }
        thread_info[i].array = A;
        thread_info[i].partial_sum = 0;
        pthread_create(&thread_info[i].thread_id, NULL, partial_sum, (void*)&thread_info[i]);
    }

    for(int i = 0; i < num_threads; i++){
        void *status;
        pthread_join(thread_info[i].thread_id, &status);
        local_sum[thread_info[i].num] = *(int *)status;
    }

    int global_sum = 0;
    for (int i = 0; i < num_threads; i++){
        global_sum += local_sum[thread_info[i].num];
    }
    average = (double)global_sum / array_size;

    fprintf(stdout, "Found average of %f\n", average);
    //Test it with sequential function
    fprintf(stdout, "seq_avg: %f\n", seq_average(A, array_size));

    free(local_sum);
    free(A);
    return 0;
}