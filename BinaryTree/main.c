#include "Tree_Global.h"
#include "Tree_Node.h"
#include "Tree_Utils.h"

void InorderTraversal(Node *root)
{
    if (!root)
        return ;
    InorderTraversal(root->left);
    printf("%c, ", *(char *)root->value);
    fflush(stdout);
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (!root)
        return ;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%c, ", *(char *)root->value);
    fflush(stdout);
}

void PreorderTraversal(Node *root)
{
    if (!root)
        return ;
    printf("%c, ", *(char *)root->value);
    fflush(stdout);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        system("cat Usage.txt");
        return (TREE_ERROR);
    }
    Node *tree = CreateDefaultTree();
    system("cat default.tree");
    while (true)
    {
        PutStringNl("\nPlease enter a command (to see command list enter 'help')");
        char command[MAX_INPUT_LIMIT];
        fgets(command, MAX_INPUT_LIMIT, stdin);

        if (Strcmp(command, "Exit\n")) {
            break ;
        }
        else if (Strcmp(command, "InOrder\n")) {
            PutStringNl("");
            PutStringNl("Tree printing -Inorder Traversal- (Left-Root-Right) (DFS)");
            InorderTraversal(tree);
            PutStringNl("");
        }
        else if (Strcmp(command, "Postorder\n")) {
            PutStringNl("");
            PutStringNl("Tree printing -Postorder Traversal- (Left-Right-Root) (DFS)");
            PostorderTraversal(tree);
            PutStringNl("");
        }
        else if (Strcmp(command, "Preorder\n")) {
            PutStringNl("");
            PutStringNl("Tree printing -Preorder Traversal- (Root-Left-Right) (DFS)");
            PreorderTraversal(tree);
            PutStringNl("");
        }
        else if (Strcmp(command, "Help\n")) {
            PutStringNl("\nExit: To exit the program");
            PutStringNl("Inorder: To print the tree in 'Inorder Traversal' (DFS)");
            PutStringNl("Postorder: To print the tree in 'Postorder Traversal' (DFS)");
            PutStringNl("Preorder: To print the tree in 'Preorder Traversal' (DFS)");
            PutStringNl("Print: Prints the tree");
            PutStringNl("Help: Prints out all the commands");
            PutStringNl("Clear: Clears the terminal");
            PutStringNl("NOT -> These command are not case sensitive so 'Exit' and 'eXit' both work");
        }
        else if (Strcmp(command, "Clear\n")) {
            system("clear");
        }
        else if (Strcmp(command, "Print\n")) {
            system("cat default.tree");
        }
    }
    FreeDefaultTree(tree);
    return (0);
}