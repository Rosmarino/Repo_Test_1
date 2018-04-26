#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    struct element *previous;
    int info;
    struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int main ()
{
    int n;
    scanf("%d", &n);
    ListOfElements l = (ListOfElements)malloc(sizeof(ElementOfList));
    scanf("%d", &l->info);
    l->previous = NULL;
    l->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        ListOfElements temp = (ListOfElements)malloc(sizeof(ElementOfList));
        scanf("%d", &temp->info);
        l->next = temp;
        temp->previous = l;
        l = l->next;
        l->next = NULL;
    }
    while (l->previous != NULL)
    {
        printf("%d\n", l->info);
        l = l->previous;
    }
    printf("%d\n", l->info);
    return 0;
}
