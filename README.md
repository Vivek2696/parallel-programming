# parallel-programming
OpenMP | pthreads | MPI

Overview of the repo

1. OpenMP: recursive parallelism
2. pthreads: simple multithreading
3. MPI: Distributed memory program

TBD:
4. Advance MPI
  - Prefix sum matrix 
  - one-sided MPI 

Sample Runs:

1. This code assumes the tree is full binary tree and finds the depth of tree using openmp recursive parallelism:
  - ![openmp_sample_run](https://github.com/Vivek2696/parallel-programming/blob/main/screenshots/openmp_recursive.PNG)

2. This is shared memory program using pthreads that computes the average distribution in parallel, by breaking the array A into smaller chuncks:
  - ![pthreads_sample_run](https://github.com/Vivek2696/parallel-programming/blob/main/screenshots/pthreads.PNG)

3. This code implements the MPI reduction collective operation such that the root process (rank 0) sum value will have the sum of each of the P process' local value:
  - ![mpi_reduce_sample_run](https://github.com/Vivek2696/parallel-programming/blob/main/screenshots/mpi_reduce.PNG)

