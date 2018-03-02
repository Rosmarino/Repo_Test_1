#include <stdio.h
#include <stdlib.h>

struct elemento
{
    int info;
    struct elemento *next;
};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void reset(int array[], int len)
{
    for (int i = 0; i < len; i ++)
        a[i] = 0;
}

void add(int array[], int len, int val)
{
    
}

int main ()
{
    ListaDiElementi l = malloc(sizeof(ElementoDiLIsta));
    int check, ok = 1;
    scanf("%d", &check);
    if (check >= 0 && check <= 9)
    {
        l->info = check;
        l->next = NULL;
    }
    else if (check == -1)
    {
        ok = 0;
        l->info = -1;
        l->next = NULL;
    }
    if (ok)
        ListaDiElementi temp = l;
    while (ok)
    {
        scanf("%d", &check);
        if (check >= 0 && check <= 9)
        {
            ListaDiElementi next = malloc(sizeof(ElementoDiLista));
            next->info = check;
            next->next = NULL;
            temp->next = next;
            temp = temp->next;
        }
        else if (check == -1)
            ok = 0;
    }
    int a[10];
    
}
