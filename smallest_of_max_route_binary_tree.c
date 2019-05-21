#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node *father; // Previous node
	struct _node *left; // Smaller or equal the key
	struct _node *right; // Bigger than the key
}NodeOfTree;
typedef NodeOfTree *BinaryTree;

typedef struct _element
{
	BinaryTree info;
	struct _element *next;
}NodeOfList;
typedef NodeOfList *ListOfNodes;

int check (BinaryTree T)
{
	int smallest = T->key;
	while (T->father != NULL)
	{
		T = T->father;
		if (T->key < smallest)
			smallest = T->key;
	}
	return smallest;
}

int main ()
{
	int n = 0, i = 0;
	scanf("%d", &n); // Number of keys
	if (n)
	{
		BinaryTree T = (BinaryTree) malloc (sizeof(NodeOfTree));
		scanf("%d", &T->key); // First key
		T->father = NULL;
		T->left = NULL;
		T->right = NULL;
		BinaryTree Root = T; // Always points to the root
		ListOfNodes l = (ListOfNodes) malloc (sizeof(NodeOfList));
		int firstocc = 1;
		l->next = NULL;
		ListOfNodes head = l;
		int max_sum = 0;
		for (i = 0; i < n - 1; i++) // Tree building
		{
			T = Root; // Reset T's position
			BinaryTree temp = (BinaryTree) malloc (sizeof(NodeOfTree));
			scanf("%d", &temp->key);
			temp->left = NULL;
			temp->right = NULL;
			int placed = 0;
			int sum = temp->key;
			while (!placed)
			{
				sum+= T->key;
				if (temp->key <= T->key) // Left node
				{
					if (T->left == NULL) // Found an empty node
					{
						T->left = temp;
						temp->father = T;
						placed++;
					}
					else
						T = T->left;
				}
				else // Right node
				{
					if (T->right == NULL) // Found an empty node
					{
						T->right = temp;
						temp->father = T;
						placed++;
					}
					else
						T = T->right;
				}
			}
			if (sum >= max_sum)
			{
				if (sum == max_sum) // New route
				{
					if (firstocc)
						l->info = temp;
					else
					{
						ListOfNodes new = (ListOfNodes) malloc (sizeof(NodeOfList));
						new->info = temp;
						new->next = NULL;
						l = l->next;
					}
				}
				else
				{
					max_sum = sum;
					l = head;
					l->next = NULL;
					l->info = temp;
				}
			}
		}
		int max = check(head->info);
		while (head->next != NULL)
		{
			head = head->next;
			int smaller = check(head->info);
			if (smaller < max)
				max = smaller;
		}
		printf("%d\n", max);
	}
	else
		printf("0\n");
	return 0;
}
