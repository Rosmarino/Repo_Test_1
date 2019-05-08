#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    struct _node *left; // Smaller than or equal the key
    struct _node *right; // Bigger than the key
    struct _node *parent;
}NodeOfTree;
typedef NodeOfTree *BinaryTree;

int main ()
{
    int n = 0, i = 0, found = 0;
    scanf("%d", &n); // Number of elements of the Binary Tree
    BinaryTree T = (BinaryTree) malloc (sizeof(NodeOfTree));
    scanf("%d", &T->key); // First element
    BinaryTree Root = T; // Always point to the Root of the tree
    T->left = NULL;
    T->right = NULL;
    T->parent = NULL;
    for (i = 1; i < n; i++) // Tree building
    {
        BinaryTree Temp = (BinaryTree) malloc (sizeof(NodeOfTree)); // New node
        Temp->left = NULL;
        Temp->right = NULL;
        Temp->parent = NULL;
        scanf("%d", &Temp->key); // Key of the new node
        T = Root; // Reset of the root
        found = 0;
        while (!found)
        {
            if (Temp->key <= T->key) // Left node
            {
                if (T->left == NULL) // Found an empty node
                {
                    T->left = Temp;
                    Temp->parent = T;
                    found++;
                }
                else
                    T = T->left;
            }
            else // Right node
            {
                if (T->right == NULL) // Found an empty node
                {
                    T->right = Temp;
                    Temp->parent = T;
                    found++;
                }
                else
                    T = T->right;
            }
        }
    }
    T = Root, i = 0;
    while(i < n) // Tree print
    {
        while (T->left != NULL) // Smallest element research
            T = T->left;
        if (T->key != (-1)) // If I haven't printed before
        {
            printf("%d\n", T->key); // Print of the smallest element
            T->key = -1; // Reset the key
            i++;
        }
        if (T->right != NULL) // Least bigger element of the smallest of this iteraction
            T = T->right;
        else if (T->parent != NULL)
        {
            T = T->parent;
            T->left = NULL;
            if (T->right != NULL)
            {
                BinaryTree Right = T->right;
                if(Right->key == (-1))
                    T->right = NULL;
            }
        }
    }
    return 0;
}
