#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element //Second list (Group of strings with the same master anagram)
{
	char info[20];
	char anagram[20];
	struct element *next;
}ElementOfGroup;
typedef ElementOfGroup *GroupOfElements;

typedef struct pointer //Main list (List of groups of strings with the same master anagram)
{
	ElementOfGroup *info;
	struct pointer *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

char *master_anagram(char string[]) //Calculates the main anagram of a string
{
	int i, j, temp;
	int n = strlen(string);
	char *string_copy = (char*)malloc((n + 1) * sizeof(char));
	strcpy(string_copy, string);
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (string_copy[i] > string_copy[j])
			{
				temp = string_copy[i];
				string_copy[i] = string_copy[j];
				string_copy[j] = temp;
			}
		}
	}
	return string_copy;
}

ListOfElements listMaker(ListOfElements head, char **A, int n)
{
	int i;
	//First group of anagrams
	GroupOfElements first = (GroupOfElements)malloc(sizeof(ElementOfGroup));
	strcpy(first->info, A[0]);
	strcpy(first->anagram, master_anagram(A[0]));
	first->next = NULL;
	head->info = first; //Adding the pointer to the first group of anagrams in the main list
	ListOfElements listTemp = head; //Copy of the principal list (to scroll)
	for (i = 1; i < n; i++) // Scrolling now the multidimensional array of strings and building the list
	{
		listTemp = head;
		//Adding the anagram to a new group of elements
		GroupOfElements groupTemp = (GroupOfElements)malloc(sizeof(ElementOfGroup));
		strcpy(groupTemp->info, A[i]);
		strcpy(groupTemp->anagram, master_anagram(A[i]));
		groupTemp->next = NULL;
		//Checking if there is another group of elements in the list with the same master anagram
		while (listTemp->next != NULL && strcmp(listTemp->info->anagram, groupTemp->anagram) != 0) //Scrolls the list
			listTemp = listTemp->next;
		if (strcmp(listTemp->info->anagram, groupTemp->anagram) == 0) //Checks if the element is found
		{
			//Now needs to order the list alphabetically

			//Biggest element case (List's top)
			if (strcmp(listTemp->info->info, groupTemp->info) > 0)
			{
				groupTemp->next = listTemp->info;
				listTemp->info = groupTemp;
			}
			//Only one element case and smallest
			if (strcmp(listTemp->info->info, groupTemp->info) <= 0 && listTemp->info->next == NULL)
				listTemp->info->next = groupTemp;
			//More than one elemens case and middle or smallest
			else
			{
				GroupOfElements previous = listTemp->info; //Pointer to the previous element
				GroupOfElements temp = listTemp->info;
				temp = temp->next;
				//Now scrolling the list
				while (strcmp(temp->info, groupTemp->info) < 0 && temp->next != NULL)
				{
					temp = temp->next;
					previous = previous->next;
				}
				//Middle element
				if (temp->next != NULL || strcmp(temp->info, groupTemp->info) > 0)
				{
					previous->next = groupTemp;
					groupTemp->next = temp;
				}
				//Smallest element
				else
					temp->next = groupTemp;
			}
		}
		//Element not found, need to add a new element of main list
		else
		{
			ListOfElements temp = (ListOfElements)malloc(sizeof(ElementOfList));
			temp->info = groupTemp;
			temp->next = NULL;
			listTemp = head; //Pointing again to the top to scroll the list
			//Biggest element case
			if (strcmp(listTemp->info->anagram, temp->info->anagram) > 0)
			{
				head = temp;
				temp->next = listTemp;
			}
			//Only one element case and smallest
			else
			{
				if (strcmp(listTemp->info->anagram, temp->info->anagram) < 0 && listTemp->next == NULL)
					head->next = temp;
				//More than one elements case and middle or smallest
				else
				{
					ListOfElements previous = listTemp; //Pointer to the previous element
					listTemp = listTemp->next;
					//Now scrolling the list
					while (strcmp(listTemp->info->anagram, temp->info->anagram) < 0 && listTemp->next != NULL)
					{
						listTemp = listTemp->next;
						previous = previous->next;
					}
					//Middle element
					if (listTemp->next != NULL || strcmp(listTemp->info->anagram, temp->info->anagram) > 0)
					{
						previous->next = temp;
						temp->next = listTemp;
					}
					//Smallest element
					else
						listTemp->next = temp;
				}
			}
		}
	}
	return head;
}


int main()
{
	int n, i;
	//Inizialization of matrix of strings
	scanf("%d", &n);
	char **A = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
	{
		A[i] = (char*)malloc(20 * sizeof(char));
		scanf("%s", A[i]);
	}
	ListOfElements l = (ListOfElements)malloc(sizeof(ElementOfList));
	l->next = NULL;
	l = listMaker(l, A, n);
	//Prints the list
	while (l->next != NULL)
	{
		while (l->info->next != NULL) //Prints each group
		{
			printf("%s ", l->info->info);
			l->info = l->info->next; //Scrolls the list
		}
		printf("%s\n", l->info->info);
		l = l->next; // Scrolls the main list
	}
	while (l->info->next != NULL) //Prints each group
	{
		printf("%s ", l->info->info);
		l->info = l->info->next; //Scrolls the list
	}
	printf("%s\n", l->info->info);
	return 0;
}
