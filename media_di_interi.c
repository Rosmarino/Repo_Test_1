#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int N, i = 0;
    float sum = 0;
    while (scanf("%d",&N) != 1 || N < 0)
    {
        printf ("Incorretto. Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    int *A = (int*)malloc(N * sizeof(int));
    while (i < N)
    {
        while (scanf("%d",&A[i]) != 1)
        {
            printf ("Incorretto. Inserisci un intero.\n");
            while(getchar() != '\n');
        }
        i++;
    }
    for (i = 0; i < N; i++)
        sum += A[i];
    printf("%.2f\n", sum / N);
    return 0;
}
