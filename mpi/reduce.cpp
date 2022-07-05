#include "mpi.h"

void my_reduce(int *my_val, int *sum_val){
    int parent, my_rank, leftchild, rightchild, nprocs;

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    //MPI ranks are logically strucutured as binary tree
    leftchild = 2 * my_rank + 1;
    rightchild = 2 * my_rank + 2;

    if(leftchild < nprocs){
        int left_sum = 0;
        MPI_Recv(&left_sum, 1, MPI_INT, leftchild, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        *sum_val += left_sum;
    }

    if(rightchild < nprocs){
        int right_sum = 0;
        MPI_Recv(&right_sum, 1, MPI_INT, rightchild, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        *sum_val += right_sum;
    }

    if(my_rank % 2 == 0){
        parent = (my_rank - 2) / 2;
    }
    else{
        parent = (my_rank - 1) / 2;
    }

    if(parent >= 0){
        *sum_val += *my_val;
        MPI_Send(sum_val, 1, MPI_INT, parent, 0, MPI_COMM_WORLD);
    }

    if(my_rank == 0){
        *sum_val += *my_val;
    }

}