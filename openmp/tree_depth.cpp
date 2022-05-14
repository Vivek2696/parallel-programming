#include <omp.h>
#include "../openmp/helper.cpp"
#include <algorithm>

#ifndef DEPTH_
#define DEPTH_


int tree_depth(node *n)
{
    if(n -> is_leaf){
        return 0;
    }
    else{
        int d1, d2;

        #pragma omp task shared(d1)
        d1 = tree_depth(n->left_child);

        #pragma omp task shared(d2)
        d2 = tree_depth(n->right_child);

        #pragma omp taskwait

        n->depth = 1 + std::max(d1, d2);
        return n->depth;
    }
}

int compute_depth(node *root)
{
    return tree_depth(root);
}

#endif
