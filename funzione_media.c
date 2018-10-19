#include <stdio.h>

float media(int A[])
{
    float media = 0; 
    int div = 1;
    if (A[0] < 0) // Media negativa
    {
        media = A[0]; // Cicla una volta di meno
        for (int i = 1; i < 10; i++)
        {
            if (A[i] < 0)
            {
                media += A[i];
                div ++;
            }
        }
    }
    else // Media positiva
    {
        media = A[0]; // Cicla una volta di meno
        for (int i = 1; i < 10; i++)
        {
            if (A[i] > 0)
            {
                media += A[i];
                div ++;
            }
        }
    }
    return media / div;
}

int main ()
{
    int A[10];
    for (int i = 0; i < 10; i++)
    {
        while (scanf("%d", &A[i]) != 1)
	    {
	        printf("Inserisci un intero.\n");
	        while(getchar() != '\n');
	    }
    }
    printf("%.2f\n", media(A));
    return 0;
}
