#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
}NodeOfTree;
typedef NodeOfTree *TreeOfNodes;

TreeOfNodes insert(TreeOfNodes t, int key, int *check)
{
	int depth = 0;
	TreeOfNodes newNode = (TreeOfNodes)malloc(sizeof(NodeOfTree));
	newNode->key = key;
	newNode->right = NULL;
	newNode->left = NULL;
	if (t == NULL)
		return newNode;
	TreeOfNodes parent;
	TreeOfNodes current = t;
	while (current != NULL)
	{
		parent = current;
		if (current->key < key)
			current = current->right;
		else
			current = current->left;
		depth++;
	}
	if (parent->key < key)
	{
		parent->right = newNode;
		depth++;
	}
	else
	{
		parent->left = newNode;
		depth++;
	}
	if (depth > *check)
		*check = depth;
	return t;
}

int main()
{
	int n, i, key, ok = 1, check = 0;
	scanf("%d", &n);
	TreeOfNodes tree = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		tree = insert(tree, key, &check);
	}
	printf("%d\n", check);
	return 0;
}
