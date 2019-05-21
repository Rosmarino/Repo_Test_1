#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _patient
{
	char name[101];
	struct _patient *next;
}PatientOfQueue;
typedef PatientOfQueue *QueueOfPatients;

int compare(const void *a, const void *b)
{
	char **a1 = (char **)a;
	char **b1 = (char **)b;
	return strcmp(*a1, *b1);
}

int main ()
{
	int c = 1, firstocc = 1, queue = 0, i = 0; // Queue = N° of patients in queue
	QueueOfPatients l;
	QueueOfPatients head; // Always points to list's top
	while (c)
	{
		scanf("%d", &c); // Event manager
		if (c == 1) // New patient in queue
		{
			if (firstocc) // First patient in the queue's end
			{
				l = (QueueOfPatients) malloc (sizeof(PatientOfQueue));
				scanf("%s", l->name);
				l->next = NULL;
				head = l;
				firstocc--;
			}
			else
			{
				QueueOfPatients temp = (QueueOfPatients) malloc (sizeof(PatientOfQueue));
				scanf("%s", temp->name);
				temp->next = NULL;
				l->next = temp;
				l = l->next;
			}
			queue++;
		}
		else if (c == 2) // Delete first patient in queue
		{
			QueueOfPatients temp = head;
			if (head->next != NULL)
				head = head->next;
			else // Last patient in queue
				firstocc++;
			free(temp);
			queue--;
		}
	}
	if (queue > 0) // If there are still patients in queue
	{
		l = head;
		char **P = (char**) malloc (queue * sizeof(char*)); // Multidimensional array of patients still in queue
		for (i = 0; i < queue; i++)
		{
			P[i] = (char*) malloc (101 * sizeof(char));
			strcpy(P[i], l->name);
			QueueOfPatients temp = l;
			l = l->next;
			free(temp);
		}
		qsort(P, queue, sizeof(char*), compare);
		for (i = 0; i < queue; i++)
			printf("%s\n", P[i]);
	}
	printf("$\n");
	return 0;
}
