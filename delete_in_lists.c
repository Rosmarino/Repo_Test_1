#include <stdio.h>
#include <stdlib.h>

typedef struct _element
{
    int info;
    struct _element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int avg (ListOfElements l, int n)
{
    int average = 0;
    for(int i = 0; i < n; i++)
    {
        average += l->info;
        l = l->next;
    }
    return average /= n;
}


int main ()
{
    int n = 0, i = 0; // N = Number of elements
    scanf("%d", &n);
    ListOfElements l = (ListOfElements) malloc (sizeof(ElementOfList)); // List
    scanf("%d", &l->info);
    l->next = NULL;
    ListOfElements head = l; // Pointer to list's top
    for (i = 1; i < n; i++) // List making
    {
        ListOfElements temp = (ListOfElements) malloc (sizeof(ElementOfList));
        scanf("%d", &temp->info);
        temp->next = NULL;
        l->next = temp;
        l = l->next;
    }
    l = head;
    int average = avg (l, n);
    printf("%d\n", average);
    l = head;
    for (i = 0; i < n; i++) // List print
    {
        printf("%d ", l->info);
        l = l->next;
    }
    printf("\n");
    l = head;
    int first = 1; // First element checker
    ListOfElements previous = l; // Points to previous's element
    for(i = 0; i < n; i++)
    {
        if (l->info <= average) // Delete element
        {
            if (first) // First element
            {
                ListOfElements temp = l;
                l = l->next;
                head = l; // New list's top
                free(temp);
                previous = l;
            }
            else if (i == n) // Last element
            {
                previous->next = NULL;
                free(l);
            }
            else // Middle element
            {
                previous->next = l->next;
                free(l);
                l = previous->next;
            }
        }
        else
        {
            if (first)
            {
                first = 0;
                l = l->next;
            }
            else
            {
                previous = previous->next;
                l = l->next;
            }
        }
    }
    while (head->next != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("%d\n", head->info);
    return 0;
}
