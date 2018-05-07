#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
}NodeOfTree;
typedef NodeOfTree *TreeOfNodes;

void printTree(TreeOfNodes node) 
{
	if (node == NULL) 
		return;   
	printTree(node->left);
	printf("%d\n", node->key);
	printTree(node->right);
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
	int n, i, key;
	scanf("%d", &n);
	TreeOfNodes tree = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		tree = insert(tree, key);
	}
	printTree(tree);
	return 0;
}
