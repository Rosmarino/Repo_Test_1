#include <stdio.h>
#include <stdlib.h>

typedef struct _list
{
    int info;
    struct _list *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int main ()
{
    int n = 0, i = 0;
    scanf("%d", &n);
    ListOfElements l = (ListOfElements) malloc (sizeof(ElementOfList));
    l->next = NULL;
    ListOfElements top = l;
    scanf("%d", &(l->info));
    for (i = 0; i < (n - 1); i++)
    {
        ListOfElements temp = (ListOfElements) malloc (sizeof(ElementOfList));
        temp->next = NULL;
        l->next = temp;
        l = l->next;
        scanf("%d", &(l->info));
    }
    int check = 0;
    ListOfElements previous = top;
    while (check >= 0)
    {
        check = 0;
        l = top; // First element of the list
        scanf("%d", &i);
        previous = top;
        while (l->next != NULL && i != l->info)
        {
            l = l->next;
            if (check > 0)
                previous = previous->next;
            check++;
        }
        if (l->info == i)
        {
            printf("%d\n", check);
            if (check != 0) // Not first element
            {
                if(l->next != NULL) // Not last element
                    previous->next = l->next;
                else // Last element
                    previous->next = NULL;
                l->next = top;
                top = l;
            }
        }
        else
        {
            check = (-1);
            printf("%d\n", check);
        }
    }
    return 0;
}
