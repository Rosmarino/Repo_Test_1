#include <stdio.h>
#include <stdlib.h>
#define p 999149

typedef struct node 
{
	int value;
	struct node *next;

}HashTable;

void hash(int x, int a, int b, int n, HashTable **H, int *distincts)
{
	int ok = 1, d = *distincts;
	int index = ((a * x + b) % p) % (2 * n);
	if (H[index]->next == NULL)
	{
		HashTable *newNode = (HashTable*)malloc(sizeof(HashTable));
		newNode->value = x;
		newNode->next = NULL;
		H[index]->next = newNode;
		d++;
	}
	else
	{
		HashTable *temp = H[index];
		while (temp->next != NULL && ok)
		{
			temp = temp->next;
			if (temp->value == x)
				ok = 0;
		}
		if (ok)
		{
			HashTable *newNode = (HashTable*)malloc(sizeof(HashTable));
			newNode->value = x;
			newNode->next = NULL;
			temp->next = newNode;
			d++;
		}
	}
	*distincts = d;
}

void check(HashTable **H, int n)
{
	int maxLenght = 1, conflicts = 0;
	for (int i = 0; i < n * 2; i++)
	{
		int currentLenght = 0;
		if (H[i]->next != NULL)
		{
			currentLenght++;
			HashTable *temp = H[i];
			if (temp->next != NULL)
			{
				temp = temp->next;
				while (temp->next != NULL)
				{
					temp = temp->next;
					currentLenght++;
					conflicts++;
				}
			}
			if (currentLenght > maxLenght)
				maxLenght = currentLenght;
		}
	}
	printf("%d\n%d\n", conflicts, maxLenght);
}

int main()
{
	int n, x, a, b, i, distincts = 0;
	scanf("%d", &n);
	scanf("%d", &a);
	scanf("%d", &b);
	HashTable **H = (HashTable **)malloc((n * 2) * sizeof(HashTable *));
	for (i = 0; i < 2 * n; i++)
	{
		H[i] = (HashTable*)malloc(sizeof(HashTable));
		H[i]->next = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		hash(x, a, b, n, H, &distincts);
	}
	check(H, n);
	printf("%d\n", distincts);
	return 0;
}
