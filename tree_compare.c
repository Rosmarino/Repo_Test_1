#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
}NodeOfTree;
typedef NodeOfTree *TreeOfNodes;

typedef struct element
{
	int info;
	struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int treeCheck(TreeOfNodes t, ListOfElements l, int k)
{
	while (l != NULL && t != NULL)
	{
		if (t->key != l->info)
			return 0;
		if (t->key == k)
			return 1;
		else
		{
			if (t->key > k)
			{
				t = t->left;
				l = l->next;
			}
			else
			{
				t = t->right;
				l = l->next;
			}
		}
	}
	return 0;
}

void listBuild(ListOfElements l, TreeOfNodes t, int k)
{
	int found = 0;
	l->info = t->key;
	while (!found && t != NULL)
	{
		if (t->key == k)
			found = 1;
		else
		{
			if (t->key > k)
				t = t->left;
			else
				t = t->right;
		}
		if (!found)
		{
			ListOfElements temp = (ListOfElements)malloc(sizeof(ElementOfList));
			temp->info = t->key;
			temp->next = NULL;
			l->next = temp;
			l = l->next;
		}
	}
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
	int n, k, i, key;
	scanf("%d%d", &n, &k);
	TreeOfNodes first = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		first = insert(first, key);
	}
	TreeOfNodes second = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		second = insert(second, key);
	}
	ListOfElements l = (ListOfElements)malloc(sizeof(ElementOfList));
	l->next = NULL;
	listBuild(l, first, k);
	printf("%d\n", treeCheck(second, l, k));
	return 0;
}
