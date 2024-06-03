#ifndef TREE_NODE_H
# define TREE_NODE_H

typedef struct _Node {
    struct _Node *right;
    struct _Node *left;
    struct _Node *parent;
    void *value;
}   Node;

#endif