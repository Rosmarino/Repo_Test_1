#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *parent;
	struct node *left;
	int key;
	int keySum;
	struct node *right;
}NodeOfTree;
typedef NodeOfTree *TreeOfNodes;

typedef struct sum
{
	int node;
	int sum;
}SumMax;
typedef SumMax *MaxSum;

int main()
{
	int N, i;
	scanf("%d", &N); // Number of keys
	if (N)
	{
		TreeOfNodes root = (TreeOfNodes)malloc(sizeof(NodeOfTree)); // Always point to the root of the binary tree
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		scanf("%d", &root->key);
		root->keySum = root->key;
		MaxSum max = (MaxSum)malloc(sizeof(SumMax)); // Checks both the max sum and the smallest element
		max->node = root->key;
		max->sum = root->key;
		for (i = 0; i < N - 1; i++) // Building of binary tree
		{
			int found = 0;
			TreeOfNodes leaf = (TreeOfNodes)malloc(sizeof(NodeOfTree)); // New node
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->parent = NULL;
			scanf("%d", &leaf->key);
			if (leaf->key <= root->key) // Left side
			{
				if (root->left == NULL) // First occurrence
				{
					root->left = leaf;
					leaf->keySum = root->keySum + leaf->key;
					max->node = leaf->key;
					max->sum = leaf->keySum;
					leaf->parent = root;
				}
				else // Scrolls the tree
				{
					TreeOfNodes temp = root; // Scrolls the tree
					temp = temp->left;
					while (!found)
					{
						if (leaf->key <= temp->key) // Left side
						{
							if (temp->left != NULL) // Keeps scrolling
								temp = temp->left;
							else
							{
								temp->left = leaf; // Adds the leaf
								leaf->keySum = temp->keySum + leaf->key;
								leaf->parent = temp;
								if (leaf->keySum > max->sum)
								{
									max->sum = leaf->keySum;
									max->node = leaf->key;
								}
								else if (leaf->keySum == max->sum && leaf->key < max->node)
									max->node = leaf->key;
								found = 1;
							}
						}
						else // Right side
						{
							if (temp->right != NULL) // Keeps scrolling
								temp = temp->right;
							else
							{
								temp->right = leaf; // Adds the leaf
								found = 1;
								leaf->keySum = temp->keySum + leaf->key;
								leaf->parent = temp;
								if (leaf->keySum > max->sum  || leaf->keySum == max->sum && leaf->key < max->node)
								{
									max->sum = leaf->keySum;
									max->node = leaf->key;
									while (leaf->parent != NULL)
									{
										leaf = leaf->parent;
										if (leaf->key < max->node)
											max->node = leaf->key;
									}
								}
							}
						}
					}
				}
			}
			else // Right side
			{
				if (root->right == NULL) // First occurrence
				{
					root->right = leaf;
					leaf->keySum = root->keySum + leaf->key;
					max->sum = leaf->keySum;
					leaf->parent = root;
				}
				else // Scrolls the tree
				{
					TreeOfNodes temp = root; // Scrolls the tree
					temp = temp->right;
					while (!found)
					{
						if (leaf->key <= temp->key) // Left side
						{
							if (temp->left != NULL) // Keeps scrolling
								temp = temp->left;
							else
							{
								temp->left = leaf; // Adds the leaf
								leaf->keySum = temp->keySum + leaf->key;
								leaf->parent = temp;
								if (leaf->keySum > max->sum)
								{
									max->sum = leaf->keySum;
									max->node = root->key;
								}
								else if (leaf->keySum == max->sum && leaf->key < max->node)
									max->node = leaf->key;
								found = 1;
							}
						}
						else // Right side
						{
							if (temp->right != NULL) // Keeps scrolling
								temp = temp->right;
							else
							{
								temp->right = leaf; // Adds the leaf
								found = 1;
								leaf->keySum = temp->keySum + leaf->key;
								leaf->parent = temp;
								if (leaf->keySum > max->sum)
								{
									max->sum = leaf->keySum;
									max->node = root->key;
								}
								else if (leaf->keySum == max->sum && leaf->key < max->node)
									max->node = leaf->key;
							}
						}
					}
				}
			}
		}
		printf("%d\n", max->node);
	}
	else
		printf("0\n");
	return 0;
}
