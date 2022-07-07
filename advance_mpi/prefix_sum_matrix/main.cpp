#include<iostream>
#include<string>
#include "mpi.h"
#include "../prefix_sum_matrix/prefix_sum.cpp"

int main(int argc, char *argv[]){

    MPI_Init(&argc, &argv);
    int myrank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    if (argc < 2) {
        fprintf(stderr, "Size of local matrix required\n");
        return 1;
    }

    int local_n = atoi(argv[1]);
    int *local_mat = (int*)malloc(sizeof(int) * local_n * local_n);
    // NOTE: index [i][j] is index i*local_mat+j

    if (argc > 2){
        srand(atoi(argv[2]) + myrank);
    }

    for (int i = 0; i < local_n*local_n; i++) {
        local_mat[i] = rand() % 200 - 100;
    }

    if(myrank == 0){
        fprintf(stdout, "Before prefix sum:\n");
    }
    //TODO: Print global matrix

    my_prefix_sum(local_n, local_mat);

    MPI_Barrier(MPI_COMM_WORLD);
    if(myrank == 0){
        fprintf(stdout, "After prefix sum:\n");
    }
    //TODO: Print global matrix

    free(local_mat);
    MPI_Finalize();
}