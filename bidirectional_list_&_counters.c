#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	struct element *previous;
	int info;
	int counter;
	struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int main()
{
	int n, i, ok = 1, counter = 0, listTail, listTop;
	scanf("%d", &n);

	//List making
	ListOfElements head = (ListOfElements)malloc(sizeof(ElementOfList));
	scanf("%d", &head->info);
	head->previous = NULL;
	head->next = NULL;
	head->counter = 0;
	ListOfElements copy = head;
	for (i = 0; i < n - 1; i++)
	{
		ListOfElements temp = (ListOfElements)malloc(sizeof(ElementOfList));
		scanf("%d", &temp->info);
		temp->next = NULL;
		temp->counter = 0;
		temp->previous = copy;
		copy->next = temp;
		copy = copy->next;
	}

	//Cycle of element searching
	while (ok)
	{
		listTop = 0;
		listTail = 0;
		counter = 0;
		copy = head;
		scanf("%d", &i);

		//Scrolls the list
		while (i != copy->info && copy->next != NULL)
		{
			copy = copy->next;
			counter++;
		}

		//Element found
		if (i == copy->info)
		{
			printf("%d\n", counter);
			copy->counter++;
			ListOfElements previous = copy;
			ListOfElements next = copy;

			//Reorders elements by their counters
			if (copy->previous != NULL)
				previous = previous->previous; //Pointer to the previous element
			else
				listTop = 1;
			if (copy->next != NULL)
				next = next->next; //Pointer to the next element
			else
				listTail = 1;
			if (!listTop && previous->counter < copy->counter) //If the element is not in the list's top
			{

				//Checks the previous element until its counter is bigger or equal to the copy's one, or reaches the list's top
				while (previous->counter < copy->counter && previous->previous != NULL)
					previous = previous->previous;
				//Now we have two cases: we reached list's top or we found an element with a bigger counter
				if (previous->previous == NULL && previous->counter < copy->counter) //If we reached the top and the top element has a smaller counter than the copy one
				{
					previous = copy->previous;
					if (!listTail) //If the element is not in the list's tail
					{
						previous->next = next;
						next->previous = previous;
					}
					else //If the element is in the list's tail
						previous->next = NULL;
					copy->previous = NULL;
					copy->next = head;
					head->previous = copy;
					head = copy;
					counter = 0;
					//Copy is put in the list's top
				}

				//If we didn't reach the top
				else
				{
					ListOfElements copy_previous = copy->previous;
					if (!listTail) //If the element is not in the list's tail
					{
						copy_previous->next = next;
						next->previous = copy_previous;
					}
					else //If the element is not in the list's tail
						copy_previous->next = NULL;
					copy->next = previous->next;
					previous->next = copy;
					copy->previous = previous;
					counter = 0;
					copy = head;
				}
			}
		}

		else
		{
			printf("-1\n");
			ok = 0;
		}
	}
	return 0;
}
