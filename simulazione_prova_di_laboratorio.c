#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient
{
	char name[101]; //Max number of chars is 100
	struct patient *next;
}PatientOfQueue;
typedef PatientOfQueue *QueueOfPatients;

int compare(const void *a, const void *b) //Sorting function
{
	char **a1 = (char **)a;
	char **b1 = (char **)b;
	return strcmp(*a1, *b1);
}

int main()
{
	int e = 1, firstOcc = 1, patientsNumber = 0, i;
	QueueOfPatients head; //Always points to the first patient of the queue
	QueueOfPatients temp; //Scans the queue
	while (e) //While the event is != 0
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
			if (head->next != NULL) //If the queue isn't empty, scrolls to the second patient
				head = head->next;
			else //If the queue is empty, we're in the first occurrence again
				firstOcc = 1;
			free(canc);
			patientsNumber--;
		}
	}
	if (patientsNumber) //If there are patients in the queue, creates a multidimensional array of patient's names to order them alphabetically with qsort
	{
		char **nameArray = (char **)malloc(patientsNumber * sizeof(char *)); //Multidimensional array
		for (i = 0; i < patientsNumber; i++) //Creates the array of patient's names and frees the memory of the queue
		{
			nameArray[i] = (char *)malloc(101 * sizeof(char));
			strcpy(nameArray[i], head->name);
			temp = head;
			head = head->next;
			free(temp);
		}
		qsort(nameArray, patientsNumber, sizeof(char*), compare); //Sorts the patients alphabetically
		for (i = 0; i < patientsNumber; i++)
			printf("%s\n", nameArray[i]);
	}
	printf("$\n"); //End of the queue
	return 0;
}
