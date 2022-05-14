#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "../openmp/helper.cpp"
#include "../openmp/tree_depth.cpp"
using namespace std::chrono;

node* create_subtree(unsigned nodes) {
    node* new_node = new node;
    if(nodes <= 1){
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        new_node->is_leaf = true;
        return new_node;
    }
    new_node->is_leaf = false;
    unsigned left_nodes = rand() % nodes + 1;
    new_node->left_child = create_subtree(left_nodes);
    new_node->right_child = create_subtree(nodes - left_nodes);
    return new_node;
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Must specify the number of nodes to be created." <<std::endl;
        exit(1);
    }
    if(argc > 2){
        srand(atoi(argv[2]));
    }

    unsigned nodes = atoi(argv[1]);
    node *root = create_subtree(nodes);

    //time the run of the "compute_depth"
    high_resolution_clock::time_point begin = high_resolution_clock::now();
    int depth = compute_depth(root);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    duration<double> duration = duration_cast<microseconds>(end - begin);
    std::cout << nodes << " nodes took " << duration.count() << " seconds. " << std::endl;
    std::cout << "Found depth of " << depth << std::endl;
}
