#include "mpi.h"

void my_reduce(int *my_val, int *sum_val){
    int parent, my_rank, leftchild, rightchild, nprocs;

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    //MPI ranks are logically strucutured as binary tree
    leftchild = 2 * my_rank + 1;
    rightchild = 2 * my_rank + 2;

    //TODO: Reduce sum_val up the tree to the root node
}