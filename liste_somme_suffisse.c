#include <stdio.h>
#include <stdlib.h>

typedef struct _element
{
    int info;
    struct _element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int list_sum(ListOfElements l)
{
    ListOfElements temp = l;
    int sum = temp->info;
    while(temp->next != NULL)
    {
        temp = temp->next;
        sum += temp->info;
    }
    return sum;
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
    for (i = 0; i < n; i++) //List print
    {
        printf("%d ", l->info);
        l = l->next;
    }
    printf("\n");
    l = head;
    int sum = list_sum(l);
    for (i = 0; i < n; i++) // Sobstitution
    {
        sum -= l->info;
        l->info = sum;
        l = l->next;
    }
    for (i = 0; i < n; i++) //List print
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
    return 0;
}
