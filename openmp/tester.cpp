#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "../openmp/helper.cpp"
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
    //TODO - Add benchmark
}
