#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
}NodeOfTree;
typedef NodeOfTree *TreeOfNodes;

int search(TreeOfNodes t, int key)
{
	int depth = 0;
	TreeOfNodes current = t;
	while (current != NULL)
	{
		if (key == current->key)
			return depth;
		if (key > current->key)
			current = current->right;
		else
			current = current->left;
		depth++;
	}
	return -1;
}

TreeOfNodes insert(TreeOfNodes t, int key)
{
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
	}
	if (parent->key < key)
		parent->right = newNode;
	else
		parent->left = newNode;
	return t;
}

int main()
{
	int n, i, key, ok = 1, check;
	scanf("%d", &n);
	TreeOfNodes tree = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		tree = insert(tree, key);
	}
	while (ok)
	{
		scanf("%d", &i);
		if (i < 0)
			ok = 0;
		else
		{
			check = search(tree, i);
			if (check == -1)
				printf("NO\n");
			else
				printf("%d\n", check);
		}
	}
	return 0;
}
