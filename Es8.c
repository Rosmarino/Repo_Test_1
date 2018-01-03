#include <stdio.h>
#include <stdlib.h>

struct elemento
{
	int info;
	struct elemento *next;
};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void addMissing(ListaDiElementi *list)
{
	ListaDiElementi temp = malloc(sizeof(ElementoDiLista));
	temp = (*list)->next;
	ListaDiElementi prec = malloc(sizeof(ElementoDiLista));
	prec = *list;
	while (temp->next != NULL)
	{
		if (prec->info > temp->info)
		{
			int check = prec->info - 1;
			while (check > temp->info)
			{
				ListaDiElementi middle = malloc(sizeof(ElementoDiLista));
				middle->info = check;
				middle->next = temp;
				prec->next = middle;
				prec = prec->next;
				check--;
			}
			temp = temp->next;
			prec = prec->next;
		}
		else
		{
			temp = temp->next;
			prec = prec->next;
		}
	}
	if (temp->next == NULL)
	{
		if (prec->info > temp->info)
		{
			int check = prec->info - 1;
			while (check > temp->info)
			{
				ListaDiElementi middle = malloc(sizeof(ElementoDiLista));
				middle->info = check;
				middle->next = temp;
				prec->next = middle;
				prec = prec->next;
				check--;
			}
		}
	}
}

void InsterOrd(ListaDiElementi *list, int *check)
{
	int n;
	int primaocc = 1;
	int ok = 1;
	ListaDiElementi previous = malloc(sizeof(ElementoDiLista));
	ListaDiElementi temp = malloc(sizeof(ElementoDiLista));
	ListaDiElementi end = malloc(sizeof(ElementoDiLista));
	previous = *list;
	end = *list;
	while (ok)
	{
		scanf("%d", &n);
		if (primaocc)
		{
			if (n >= 0)
			{
				(*list)->info = n;
				(*list)->next = NULL;
				temp = *list;
				primaocc = 0;
			}
			else
			{
				ok = 0;
				*check = 0;
			}
		}
		else
		{
			if (n >= 0)
			{
				// only one element case
				if (temp->next == NULL)
				{
					// n is the smallest
					if (n <= temp->info)
					{
						ListaDiElementi tail = malloc(sizeof(ElementoDiLista));
						tail->info = n;
						tail->next = NULL;
						temp->next = tail;
						end = tail;
					}
					// n is the biggest
					else
					{
						ListaDiElementi head = malloc(sizeof(ElementoDiLista));
						head->info = n;
						head->next = temp;
						temp = head;
						previous = head;
						*list = head;
					}
				}
				// two or more elements case
				else
				{
					// n is the biggest
					if (temp->info < n)
					{
						ListaDiElementi head = malloc(sizeof(ElementoDiLista));
						head->info = n;
						head->next = temp;
						temp = head;
						*list = head;
						previous = head;
					}
					// n is in the middle
					else if (end->info < n)
					{
						previous = temp;
						temp = temp->next;
						while (temp->info >= n && temp->next != NULL)
						{
							previous = previous->next;
							temp = temp->next;
						}
						ListaDiElementi middle = malloc(sizeof(ElementoDiLista));
						middle->info = n;
						middle->next = temp;
						temp = *list;
						previous->next = middle;
					}
					// n is the smallest
					else
					{
						ListaDiElementi tail = malloc(sizeof(ElementoDiLista));
						tail->info = n;
						tail->next = NULL;
						end->next = tail;
						end = tail;
					}
				}
			}
			else
			{
				ok = 0;
			}
		}
	}
}

int main()
{
	ListaDiElementi list = malloc(sizeof(ElementoDiLista));
	int ok = 1;
	InsterOrd(&list, &ok);
	if (ok)
	{
		addMissing(&list);
		while (list->next != NULL)
		{
			printf("%d --> ", list->info);
			list = list->next;
		}
		printf("%d --> NULL", list->info);
	}
	else
		printf("NULL\n");
	return 0;
}