#include <stdio.h>
#include <stdlib.h>

typedef struct _node // Binary tree
{
	struct _node *left;
	int key;
	struct _node *right;
}NodeOfTree;
typedef NodeOfTree *BinaryTree;

int compare(const void *a, const void *b)
{
	const NodeOfTree *a1 = *(const NodeOfTree **)a;
	const NodeOfTree *b1 = *(const NodeOfTree **)b;
	return (a1->key - b1->key);
}

int leftCheck(BinaryTree t) // Counts the number of the left elements of the current node
{
	if (t->left != NULL)
		return 1 + leftCheck(t->left);
}

int rightCheck(BinaryTree t) // Counts the number of the right elements of the current node
{
	if (t->right != NULL)
		return 1 + rightCheck(t->right);
}

int main()
{
	int N, i;
	scanf("%d", &N); // Number of elements
	BinaryTree root = (BinaryTree)malloc(sizeof(NodeOfTree)); // First element of the binary tree (root)
	root->left = NULL;
	root->right = NULL;
	scanf("%d", &root->key);
	BinaryTree *A = (BinaryTree*)malloc(N * (sizeof(NodeOfTree))); // Array of pointers to binary tree elements
	A[0] = root;
	BinaryTree tempTree; // Scrolls the tree
	for (i = 1; i < N; i++)
	{
		int found = 0;
		tempTree = root;
		BinaryTree leaf = (BinaryTree)malloc(sizeof(NodeOfTree));
		scanf("%d", &leaf->key);
		leaf->left = NULL;
		leaf->right = NULL;
		while (!found)
		{
			if (leaf->key <= tempTree->key) //Left node
			{
				if (tempTree->left == NULL) // Allocates the leaf
				{
					tempTree->left = leaf; // Points to the new leaf
					A[i] = leaf;
					found = 1;
				}
				else
					tempTree = tempTree->left; // Keeps scrolling
			}
			else // Right node
			{
				if (tempTree->right == NULL) // Allocates the leaf
				{
					tempTree->right = leaf; // Points to the new leaf
					A[i] = leaf;
					found = 1;
				}
				else
					tempTree = tempTree->right; // Keeps scrolling
			}
		}
	}
	qsort(A, N, sizeof(NodeOfTree*), compare); // Sorts the pointers by node's keys in ascending order
	for (i = 0; i < N; i++)
	{
		if (leftCheck(A[i]) > rightCheck(A[i])) // Prints the nodes with "L(u) > (Ru)"
			printf("%d\n", A[i]->key);
	}
	return 0;
}
