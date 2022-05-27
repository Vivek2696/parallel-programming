#include <pthread.h>

struct thread_info_struct
{
    int num;
    int start;
    int end;
    int *array;
    pthread_t thread_id;
    int partial_sum;
};