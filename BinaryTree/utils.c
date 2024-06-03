#include "Tree_Global.h"
#include "Tree_Node.h"

void PutString(const char *str)
{
    if (!str) {
        return ;
    }

    for (unsigned int i = 0; str[i] != '\0'; i++) {
        write(STDOUT_FILENO, &str[i], 1);
    }
}

void PutStringNl(const char *str)
{
    if (!str) {
        write(STDOUT_FILENO, "\n", 1);
        return ;
    }

    for (unsigned int i = 0; str[i] != '\0'; i++) {
        write(STDOUT_FILENO, &str[i], 1);
    }
    write(STDOUT_FILENO, "\n", 1);
}

int Strlen(const char *str)
{
    if (!str) {
        return (0);
    }
    int i = 0;
    for (i; str[i] != '\0'; i++);
    return (i);
}

char *Strdup(const char *str)
{
    if (!str) {
        return (NULL);
    }
    int size = Strlen(str);
    char *new = (char *)malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (i; i < size; i++) {
        new[i] = str[i];
    }
    new[i] = '\0';
    return (new);
}

bool Strcmp(const char *s1, const char *s2)
{
    if (!s1 || !s2 || (Strlen(s1) != Strlen(s2))) {
        return (false);
    }
    int size = Strlen(s1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i] &&
            s1[i] + 32 != s2[i] &&
            s1[i] - 32 != s2[i]) {
            return (false);
        }
    }
    return (true);
}

Node *CreateEmptyNode()
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->left = NULL;
    new->right = NULL;
    new->value = NULL;
    new->parent = NULL;
}

Node *CreateDefaultTree()
{
    char *one = Strdup("1");
    char *two = Strdup("2");
    char *three = Strdup("3");
    char *four = Strdup("4");
    char *five = Strdup("5");

    Node *root = CreateEmptyNode();
    Node *nTwo = CreateEmptyNode();
    Node *nThree = CreateEmptyNode();
    Node *nFour = CreateEmptyNode();
    Node *nFive = CreateEmptyNode();

    root->value = one;
    root->left = nTwo;
    root->right = nThree;
    root->parent = NULL;

    nTwo->value = two;
    nTwo->left = NULL;
    nTwo->right = NULL;
    nTwo->parent = root;

    nThree->value = three;
    nThree->left = nFour;
    nThree->right = nFive;
    nThree->parent = root;

    nFour->value = four;
    nFour->left = NULL;
    nFour->right = NULL;
    nFour->parent = nThree;

    nFive->value = five;
    nFive->left = NULL;
    nFive->right = NULL;
    nFive->parent = nThree;
    return (root);
}

void FreeDefaultTree(Node *root)
{
    Node *nTwo = root->left;
    Node *nThree = root->right;
    Node *nFour = nThree->left;
    Node *nFive = nThree->right;

    free(root->value);
    free(root);
    free(nTwo->value);
    free(nTwo);
    free(nThree->value);
    free(nThree);
    free(nFour->value);
    free(nFour);
    free(nFive->value);
    free(nFive);
}