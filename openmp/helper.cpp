#ifndef NODE_
#define NODE_

struct node {
    bool is_leaf;
    node *left_child;
    node *right_child;
    int depth;
};

#endif
