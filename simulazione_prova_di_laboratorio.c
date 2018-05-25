#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient
{
	char name[101];
	struct patient *next;
}PatientOfQueue;
typedef PatientOfQueue *QueueOfPatients;

int compare(const void *a, const void *b)
{
	char **a1 = (char **)a;
	char **b1 = (char **)b;
	return strcmp(*a1, *b1);
}

int main()
{
	int e = 1, firstOcc = 1, patientsNumber = 0, i;
	QueueOfPatients head;
	QueueOfPatients temp; //Scans the queue
	while (e)
	{
		scanf("%d", &e);
		if (e == 1 && firstOcc) //First patient of queue
		{
			head = (QueueOfPatients)malloc(sizeof(PatientOfQueue));
			head->next = NULL;
			scanf("%s", &head->name);
			temp = head;
			firstOcc = 0;
			patientsNumber++;
		}
		else if (e == 1) //Add a patient in the end of the queue
		{
			QueueOfPatients next = (QueueOfPatients)malloc(sizeof(PatientOfQueue));
			scanf("%s", &next->name);
			next->next = NULL;
			temp->next = next;
			temp = temp->next;
			patientsNumber++;
		}
		else if (e == 2) //Delete first patient of queue
		{
			QueueOfPatients canc = head;
			if (head->next != NULL)
				head = head->next;
			else
				firstOcc = 1;
			free(canc);
			patientsNumber--;
		}
	}
	if (patientsNumber)
	{
		char **nameArray = (char **)malloc(patientsNumber * sizeof(char *)); //Multidimensional array of patient's names
		for (i = 0; i < patientsNumber; i++) //Creates the array of patient's names and frees the memory of the Queue
		{
			nameArray[i] = (char *)malloc(101 * sizeof(char));
			strcpy(nameArray[i], head->name);
			temp = head;
			head = head->next;
			free(temp);
		}
		qsort(nameArray, patientsNumber, sizeof(char*), compare);
		for (i = 0; i < patientsNumber; i++)
			printf("%s\n", nameArray[i]);
	}
	printf("$\n");
	return 0;
}
