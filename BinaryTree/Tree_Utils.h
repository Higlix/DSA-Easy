#ifndef TREE_UTILS_H
# define TREE_UTILS_H

# include "Tree_Utils.h"

Node *CreateDefaultTree();
void FreeDefaultTree(Node *root);

bool Strcmp(const char *s1, const char *s2);

/* String output functions */
void PutString(const char *str);
void PutStringNl(const char *str);

#endif