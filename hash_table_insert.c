#include <stdio.h>
#include <stdlib.h>
#define p 999149

typedef struct node 
{
	int value;
	struct node *next;

}HashTable;

void hash(int x, int a, int b, int n, HashTable **H)
{
	int index = ((a * x + b) % p) % (2 * n);
	if (H[index]->next == NULL)
	{
		HashTable *newNode = (HashTable*)malloc(sizeof(HashTable));
		newNode->value = x;
		newNode->next = NULL;
		H[index]->next = newNode;
	}
	else
	{
		HashTable *temp = H[index];
		while (temp->next != NULL)
			temp = temp->next;
		HashTable *newNode = (HashTable*)malloc(sizeof(HashTable));
		newNode->value = x;
		newNode->next = NULL;
		temp->next = newNode;
	}
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
	printf("%d\n%d\n", maxLenght, conflicts);
}

int main()
{
	int n, x, a, b, i;
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
		hash(x, a, b, n, H);
	}
	check(H, n);
	return 0;
}
