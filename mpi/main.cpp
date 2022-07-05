#include "../mpi/reduce.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(argc > 1){
        srand(atoi(argv[1])+my_rank);
    }    

    int local_val = rand() % 500;
    fprintf(stderr, "rank %d has local value of %i\n", my_rank, local_val);
    int sum = 0;

    my_reduce(&local_val, &sum);

    MPI_Barrier(MPI_COMM_WORLD);
    
    if(my_rank == 0){
        fprintf(stdout, "Sum is %d\n",sum);
    }

    MPI_Finalize();

    return 0;
}