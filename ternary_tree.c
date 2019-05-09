#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    struct _node *left; // Smaller than the current key
    struct _node *center; // Divisible by the current key
    struct _node *right; // Bigger than the current key
}NodeOfTree;
typedef NodeOfTree *TernaryTree;

int check (TernaryTree T)
{
    if (T->left != NULL && T->center != NULL && T->right != NULL)
        return 1;
    else
        return 0;
}

int main ()
{
    int n = 0, i = 0, counter = 0, found = 0;
    scanf("%d", &n); // Number of nodes
    TernaryTree T = (TernaryTree) malloc (sizeof(NodeOfTree));
    scanf("%d", &T->key); // First node
    TernaryTree Root = T; // Always points to the root of the tree
    T->left = NULL;
    T->center = NULL;
    T->right = NULL;
    for (i = 1; i < n; i++) // Tree building
    {
        TernaryTree Temp = (TernaryTree) malloc (sizeof(NodeOfTree));
        scanf("%d", &Temp->key);
        Temp->left = NULL;
        Temp->center = NULL;
        Temp->right = NULL;
        T = Root;
        found = 0;
        while (!found)
        {
            if (Temp->key % T->key == 0) // Central node
            {
                if(T->center == NULL)
                {
                    T->center = Temp;
                    counter += check(T);
                    found++;
                }
                else
                    T = T->center;
            }
            else if (Temp->key < T->key) // Left node
            {
                if(T->left == NULL)
                {
                    T->left = Temp;
                    counter += check(T);
                    found++;
                }
                else
                    T = T->left;
            }
            else
            {
                if(T->right == NULL)
                {
                    T->right = Temp;
                    counter+= check(T);
                    found++;
                }
                else
                    T = T->right;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}
