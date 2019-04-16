#include <stdio.h>
#include <stdlib.h>

typedef struct _element
{
    int info;
    int counter;
    struct _element *next;
    struct _element *previous;
}ElementOfList;
typedef ElementOfList *ListOfElements;

int main ()
{
    int N = 0, i = 0;
    scanf("%d", &N); // Number of elements
    ListOfElements l = (ListOfElements) malloc (sizeof(ElementOfList)); // First element of the list
    scanf("%d", &(l->info));
    l->counter = 0;
    l->next = NULL;
    l->previous = NULL;
    ListOfElements top = l; // Copy of the top of the list
    for (i = 0; i < (N - 1); i++)
    {
        ListOfElements temp = (ListOfElements) malloc (sizeof(ElementOfList)); // Temporary variable of each new element of the list
        scanf("%d", &(temp->info));
        temp->previous = l;
        temp->next = NULL;
        temp->counter = 0;
        l->next = temp;
        l = l->next; // Scanning the list
    }
    int check = 0; // Counters the element's position in the list
    while (check != (-1)) // While I still find the element I look for in the list
    {
        int found = 0; // Checks if I found the element
        check = 0;
        scanf("%d", &i); // Element I'm looking for
        l = top; // Going back to first element
        while (l->next != NULL && i != l->info) // While the list is not over and I haven't found the element
        {
            check++; // Increase counter
            l = l->next; // Scan list
        }
        if (l->info == i) // If I found the element
            found = 1;
        if (found)
        {
            ListOfElements temporary = l;
            l->counter++;
            if (l->next == NULL) // If I'm in the last element
            {
                temporary = l->previous; // Temporary is now the last element of the list
                if (temporary->counter < l->counter) // If previous element's counter is < of l's counter
                {
                    temporary = l->previous; // Temporary is now the last element of the list
                    temporary->next = NULL;
                    l->previous = NULL; // "l" is now indipendent
                }
                else
                    found = 0; // Now I use "found" to look if actually I need to scan the list
            }
            else if (check) // Middle of the list, not last element, not first element
            {
                temporary = l->previous;
                if (temporary->counter < l->counter) // If previous element's counter is < of l's counter
                {
                    temporary->next = l->next;
                    temporary = l->next;
                    temporary->previous = l->previous; // List is back to normal without l
                    l->next = NULL;
                    l->previous = NULL; // "l" is now indipendent
                }
                else
                    found = 0;
            }
            if (found) // If I need to scan the list
            {
                ListOfElements backup = top; // Points at the list's top
                while (backup->counter >= l->counter)
                    backup = backup->next; // Scan the list
                if (backup->previous == NULL) //If I'm in the first element of list
                {
                    backup->previous = l;
                    l->next = backup;
                    top = l;
                }
                else // I can't be in the last element since if I was I wouldn't have had to scan the list
                {
                    ListOfElements previous = backup->previous;
                    previous->next = l;
                    l->previous = previous;
                    l->next = backup;
                    backup->previous = l;
                }
            }
        }
        else
            check = (-1);
        printf("%d\n", check);
    }
    return 0;
}
