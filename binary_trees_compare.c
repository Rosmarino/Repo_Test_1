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

typedef struct _element
{
    int info;
    struct _element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

BinaryTree Build(BinaryTree T, int n)
{
    int found = 0;
    T = (BinaryTree) malloc (sizeof(NodeOfTree));
    scanf("%d", &T->key); // First element
    BinaryTree Root = T; // Always point to the Root of the tree
    T->left = NULL;
    T->right = NULL;
    T->parent = NULL;
    for (int i = 1; i < n; i++) // Tree building
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
    return Root;
}

ListOfElements RouteTracer (ListOfElements Route, BinaryTree T, int k)
{
    Route = (ListOfElements) malloc (sizeof(ElementOfList));
    Route->info = T->key; // First element of route
    Route->next = NULL;
    ListOfElements Head = Route; // Always points to the first element
    while (T->key != k) // While we haven't found the element k in the tree
    {
        while (T->key > k && T->left != NULL)
        {
            T = T->left;
            ListOfElements temp = (ListOfElements) malloc (sizeof(ElementOfList)); // Adding elements to the route
            temp->info = T->key;
            temp->next = NULL;
            Route->next = temp;
            Route = Route->next;
        }
        if(T->key < k && T->right != NULL)
        {
            T = T->right;
            ListOfElements temp = (ListOfElements) malloc (sizeof(ElementOfList)); // Adding elements to the route
            temp->info = T->key;
            temp->next = NULL;
            Route->next = temp;
            Route = Route->next;
        }
    }
    return Head;
}


int main ()
{
    int n = 0, k = 0;
    scanf("%d%d", &n, &k); // Number of elements of each Binary Tree
    BinaryTree T1 = Build(T1, n); // First binary tree
    BinaryTree T2 = Build(T2, n); // Second binary tree
    ListOfElements Route1 = RouteTracer(Route1, T1, k); // Route of the first tree to the element K
    ListOfElements Route2 = RouteTracer(Route2, T2, k); // Route of the first tree to the element K
    int ok = 1;
    while (ok && Route1->next != NULL && Route2->next != NULL)
    {
        if (Route1->info != Route2->info)
            ok = 0;
        Route1 = Route1->next;
        Route2 = Route2->next;
    }
    if (Route1->info != Route2->info)
        ok = 0;
    printf("%d\n", ok);
    return 0;
}
