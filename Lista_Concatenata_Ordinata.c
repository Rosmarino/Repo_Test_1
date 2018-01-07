#include <stdio.h>
#include <stdlib.h>

struct elemento
{
	int info;
	struct elemento *next;
};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void listPrint(ListaDiElementi *l)
{
	while ((*l)->next != NULL)
	{
		printf("%d -> ", (*l)->info);
		*l = (*l)->next;
	}
	printf("%d -> NULL\n", (*l)->info);
}

void listOrder(ListaDiElementi *l)
{
	ListaDiElementi temp = *l;
	ListaDiElementi previous = *l;
	int check;
	int ok = 1;
	int first = 1;
	//Prima occorrenza
	scanf("%d", &check);
	if (check != 0)
	{
		temp->info = check;
		temp->next = NULL;
	}
	else
	{
		ok = 0;
		first = 0;
	}
	//Seconda occorrenza
	if (ok)
	{
		scanf("%d", &check);
		if (check != 0)
		{
			if (check >= temp->info)
			{
				ListaDiElementi tail = malloc(sizeof(ElementoDiLista));
				tail->info = check;
				tail->next = NULL;
				temp->next = tail;
			}
			else if (check < temp->info)
			{
				ListaDiElementi head = malloc(sizeof(ElementoDiLista));
				head->info = check;
				head->next = temp;
				temp = head;
			}
			else
				ok = 0;
		}
	}
	//Finché non inserisco uno 0 continua ad inserire elementi in lista, in ordine crescente
	while (ok)
	{
		scanf("%d", &check);
		//Se check è diverso da 0 inserisce l'elemento in lista
		if (check != 0)
		{
			//Caso in cui l'elemento sia il più piccolo
			if (check < temp->info)
			{
				ListaDiElementi head = malloc(sizeof(ElementoDiLista));
				head->info = check;
				head->next = temp;
				temp = head;
			}
			else
			//Caso in cui l'elemento sia nel mezzo ad altri due
			{
				ListaDiElementi temp2 = temp;
				temp2 = temp2->next;
				ListaDiElementi previous = temp;
				int trovato = 0;
				while (temp2->next != NULL && !trovato)
				{
					if (check < temp2->info)
					{
						ListaDiElementi middle = malloc(sizeof(ElementoDiLista));
						middle->info = check;
						middle->next = temp2;
						previous->next = middle;
						trovato = 1;
					}
					else
					{
						temp2 = temp2->next;
						previous = previous->next;
					}
				}
				//Caso in cui l'elemento sia in fondo
				if (!trovato)
				{
					if (check < temp2->info)
					{
						ListaDiElementi middle = malloc(sizeof(ElementoDiLista));
						middle->info = check;
						middle->next = temp2;
						previous->next = middle;
					}
					else
					{
						ListaDiElementi tail = malloc(sizeof(ElementoDiLista));
						tail->info = check;
						tail->next = NULL;
						temp2->next = tail;
					}
				}
			}
		}
		//Altrimenti esce dal ciclo
		else
			ok = 0;
	}
	//Stampa la lista se ha almeno un elemento
	if (first)
		listPrint(&temp);
	//Altrimenti stampa NULL\n
	else
		printf("NULL\n");
}

int main()
{
	ListaDiElementi l = malloc(sizeof(ElementoDiLista));
	listOrder(&l);
	return 0;
}
