#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int info;
    struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int main ()
{
    int n, ok = 1, i;
    scanf("%d", &n);
    ListOfElements l = (ListOfElements)malloc(sizeof(ElementOfList));
    scanf("%d", &l->info);
    l->next = NULL;
    ListOfElements l_copy = l;
    for (i = 0; i < n - 1; i++)
    {
        ListOfElements temp = (ListOfElements)malloc(sizeof(ElementOfList));
        scanf("%d", &temp->info);
        temp->next = NULL;
        l_copy->next = temp;
        l_copy = l_copy->next;
    }
    while (ok)
    {
        l_copy = l;
        int found = 0, counter = 0;
        scanf("%d", &i);
        if (l_copy->info == i)
            printf("0\n");
        else
        {
            counter++;
            ListOfElements previous = l_copy;
            while (l_copy->next != NULL && !found)
            {
                l_copy = l_copy->next;
                if(l_copy->info == i)
                {
                    printf("%d\n", counter);
                    previous->next = l_copy->next;
                    l_copy->next = l;
                    l = l_copy;
                    found = 1;
                }
                else
                {
                    counter ++;
                    previous = previous->next;
                }
            }
            if (l_copy->next == NULL && !found)
            {
                printf("-1\n");
                ok = 0;
            }
        }
    }
    return 0;
}
