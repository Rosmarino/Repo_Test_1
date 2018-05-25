#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int value;
    struct element *next;
}ElementOfList;
typedef ElementOfList *ListOfElements;

void listPrint (ListOfElements l)
{
    while (l->next != NULL)
    {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("%d\n", l->value);
}

int avg (ListOfElements l)
{
    int average = 0, counter = 0; //Average value and number of elements
    while (l->next != NULL)
    {
        average += l->value;
        counter++;
        l = l->next;
    }
    average += l->value;
    counter++;
    return average/counter;
}

ListOfElements listDelete (ListOfElements l, int average)
{
    int first = 1; //First element of list
    ListOfElements previous = l; //Pointer to the previous element
    ListOfElements temp = l;
    while (temp->next != NULL)
    {
        if (first) //First element case
        {
            if (temp->value <= average) //Delete first element
            {
                ListOfElements canc = temp;
                temp = temp->next;
                l = temp;
                previous = previous->next;
                free(canc);
            }
            else //Don't delete first element
            {
                first = 0;
                temp = temp->next;
            }
        }
        else //Middle element case
        {
            if (temp->value <= average) //Delete middle element
            {
                ListOfElements canc = temp;
                temp = temp->next;
                previous->next = temp;
                free(canc);
            }
            else
            {
                temp = temp->next;
                previous = previous->next;
            }
        }
    }
    if (temp->value <= average)//Delete last element
    {
        previous->next = NULL;
        free(temp);
    }
    return l;
}

int main ()
{
    int n;
    scanf("%d", &n);
    ListOfElements head = (ListOfElements)malloc(sizeof(ElementOfList)); //List's head
    scanf("%d", &head->value);
    head->next = NULL;
    ListOfElements temp = head; //Copy of main list
    for (int i = 0; i < n - 1; i++)
    {
        ListOfElements next = (ListOfElements)malloc(sizeof(ElementOfList));
        scanf("%d", &next->value);
        next->next = NULL;
        temp->next = next;
        temp = temp->next;
    }
    int average = avg(head);
    printf("%d\n", average);
    listPrint(head);
    head = listDelete(head, average);
    listPrint(head);
    return 0;
}
