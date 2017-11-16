#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int info;
    struct elemento *next;
};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista* ListaDiElementi;

void tailAdd (ListaDiElementi *list, int temp)
{
    ListaDiElementi check = *list;
    while (check->next != NULL)
        check = check->next;
    ListaDiElementi tail = malloc (sizeof (ElementoDiLista));
    tail->info = temp;
    tail->next = NULL;
    check->next = tail;
}

void noseAdd (ListaDiElementi *list, int temp)
{
    ListaDiElementi head = malloc (sizeof (ElementoDiLista));
    head->info = temp;
    head->next = *list;
    *list = head;
}

void listCheck (ListaDiElementi *list, int n)
{
    ListaDiElementi temp = *list;
    int trovato = 0;
    if (temp->next == NULL)
    {
        if (temp->info <= n)
            tailAdd (&*list, n);
        else
            noseAdd (&*list, n);
    }
    else
    {
        if (temp->info >= n)
            noseAdd (&*list, n);
        else
        {
            ListaDiElementi temp2 = temp->next;
            while (!trovato && temp2->next !=NULL)
            {
                if (temp2->info > n)
                {
                    ListaDiElementi middle = malloc (sizeof (ElementoDiLista));
                    middle->info = n;
                    middle->next = temp2;
                    temp->next = middle;
                    trovato = 1;
                }
                else if (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                    temp = temp->next;
                }
            }
            if (temp2->next == NULL && !trovato)
            {
                if (temp2->info <= n)
                    tailAdd (&*list, n);
                else
                {
                    ListaDiElementi middle = malloc (sizeof (ElementoDiLista));
                    middle->info = n;
                    middle->next = temp2;
                    temp->next = middle;
                }
            }
        }
    }
}

void doublesCheck (ListaDiElementi *l, int n)
{
    int ok = 1;
    ListaDiElementi temp = *l;
    while (ok)
    {
        if (temp->next == NULL)
        {
            if (temp->info == n)
                ok = 0;
            else
            {
                listCheck (&*l, n);
                ok = 0;
            }
        }
        else if (temp->info == n)
            ok = 0;
        else
            temp = temp->next;
    }
}

void listPair (ListaDiElementi *l1, ListaDiElementi *l2)
{
    ListaDiElementi copy1 = *l1;
    ListaDiElementi copy2 = *l2;
    //Creo un puntatore all'inizio di lista2
    ListaDiElementi copycopy2 = copy2;
    //Creo la terza lista in cui andrò ad inserire l'intesezione della lista 1 con la lista 2
    ListaDiElementi l3 = malloc (sizeof (ElementoDiLista));
    int finelista = 0;
    //Mi serve per controllare se la lista3 è vuota
    int primaocc = 1;
    //Mi serve per sapere finché non sono a fine lista 1
    int ok1 = 1;
    //Mi serve per sapere finché non sono a fine lista 2
    int ok2 = 1;
    while (ok1)
    {
        while (ok2)
        {
            //Se sono a fine lista 1
            if (copy1->next == NULL)
            {
                //Se l'elemento a fine lista 1 compare in lista 2 eseguo listCheck ed esco dal ciclo
                if (copy1->info == copy2->info)
                {
                    doublesCheck (&l3, copy1->info);
                    copy2 = copy2->next;
                    ok1 = 0;
                    ok2 = 0;
                }
                else if (copy2->next == NULL)
                {
                    ok1 = 0;
                    ok2 = 0;
                }
                //Se l'elemento a fine lista 1 non compare in lista 2 esco comunque dal ciclo
                else
                    copy2 = copy2->next;
            }
            //Se lista 3 è vuota
            else if (primaocc && copy1->info == copy2->info)
            {
                l3->info = copy1->info;
                l3->next = NULL;
                primaocc = 0;
                ok2 = 0;
            }
            //Se la lista non è vuota
            else if (copy1->info == copy2->info && copy2->next != NULL)
            {
                doublesCheck (&l3, copy1->info);
                copy2 = copy2->next;
            }
            //Se sono a fine lista 2
            else if (copy2->next == NULL)
            {
                //Se l'elemento in fondo a lista 2 compare in lista 1
                if (copy1->info == copy2->info)
                {
                    doublesCheck (&l3, copy1->info);
                    ok2 = 0;
                }
                else
                    ok2 = 0;
            }
            //Se l'elemento di lista 1 non è uguale a quello di lista 2, aumento lista 2
            else
                copy2 = copy2->next;
        }
        //Finito di controllare se tutti gli elementi di lista 2 compaiono in lista 1, aumento lista 1 e resetto lista 2
        if (ok1)
        {
            copy1 = copy1->next;
            copy2 = copycopy2;
            ok2 = 1;
        }
    }
    //Adesso posso stampare lista 3
    while (l3->next != NULL)
    {
        printf ("%d\n", l3->info);
        l3 = l3->next;
    }
    printf ("%d\n", l3->info);
}   

int main ()
{
    ListaDiElementi l1 = malloc (sizeof (ElementoDiLista));
    ListaDiElementi l2 = malloc (sizeof (ElementoDiLista));
    int ok = 1;
    int check = 1;
    int temp;
    while (ok)
    {
        scanf ("%d", &temp);
        if (temp > 0)
        {
            l1->info = temp;
            l1->next = NULL;
            ok = 0;
        }
    }
    while (!ok)
    {
        scanf ("%d", &temp);
        if (temp < 0)
            ok = 1;
        else
            listCheck (&l1, temp);
    }
    while (ok && check)
    {
        scanf ("%d", &temp);
        if (temp >= 0)
        {
            l2->info = temp;
            l2->next = NULL;
            ok = 0;
        }
        else
            check = 0;
    }
    while (!ok)
    {
        scanf ("%d", &temp);
        if (temp < 0)
        {
            listPair (&l1, &l2);
            ok = 1;
        }
        else
            listCheck (&l2, temp);
    }
    return 0;
}