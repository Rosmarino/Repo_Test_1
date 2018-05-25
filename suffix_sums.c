#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int value;
	struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

void listPrint(ListOfElements l)
{
	while (l->next != NULL)
	{
		printf("%d ", l->value);
		l = l->next;
	}
	printf("%d\n", l->value);
}

void suffixSums(ListOfElements l)
{
	int sum = 0;
	ListOfElements temp = l;
	while (temp->next != NULL)
	{
		temp = temp->next;
		sum += temp->value;
	}
	l->value = sum;
	if (l->next != NULL)
		suffixSums(l->next);
	else
		l->value = 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	ListOfElements head = (ListOfElements)malloc(sizeof(ElementOfList)); //List's head
	scanf("%d", &head->value);
	head->next = NULL;
	ListOfElements temp = head; //Copy of main list
	for (int i = 0; i < n - 1; i++)
	{
		ListOfElements next = (ListOfElements)malloc(sizeof(ElementOfList));
		scanf("%d", &next->value);
		next->next = NULL;
		temp->next = next;
		temp = temp->next;
	}
	listPrint(head);
	suffixSums(head);
	listPrint(head);
	return 0;
}
