#include <stdio.h>
#include <stdlib.h>

typedef struct coords
{
    unsigned long int x;
    unsigned long int y;
    unsigned long int c;
}CoordsOfArray;
typedef CoordsOfArray *ArrayOfCoords;

typedef struct interrogation
{
    unsigned long int x1;
    unsigned long int y1;
    unsigned long int x2;
    unsigned long int y2;
}InterrogationOfArray;
typedef InterrogationOfArray *ArrayOfInterrogations;

void check (ArrayOfCoords A[], ArrayOfInterrogations R[], int N, int M)
{
    int *C = (int *)malloc(M * sizeof(int));
    int i, counter;
    for (int j = 0; j < M; j++)
    {
        int *ArrayOfColours = (int *)malloc(N * sizeof(int));
        counter = 0;
        int z = 0;
        for (i = 0; i < N; i++)
        {
            int ok = 1;
            if (A[i]->x >= R[j]->x1 && A[i]->x <= R[j]->x2 && A[i]->y >= R[j]->y1 && A[i]->y <= R[j]->y2)
            {
                if (!z)
                {
                    ArrayOfColours[z] = A[i]->c;
                    z++;
                    counter++;
                }
                else
                {
                    for (int f = 0; f < z && ok; f++)
                        if (A[i]->c == ArrayOfColours[f])
                            ok = 0;
                    if (ok)
                    {
                    ArrayOfColours[z] = A[i]->c;
                        counter++;
                        z++;
                    }
                }
            }
        }
        C[j] = counter;
        free (ArrayOfColours);
    }
    for (i = 0; i < M; i++)
        printf("%d\n", C[i]);
}

int main ()
{
    int N, M, i;
    scanf("%d%d", &N, &M);
    ArrayOfCoords *A = (ArrayOfCoords *)malloc(N * sizeof(CoordsOfArray*));
    ArrayOfInterrogations *R = (ArrayOfInterrogations *)malloc(M * sizeof(InterrogationOfArray*));
    for (i = 0; i < N; i++)
    {
        A[i] = (ArrayOfCoords)malloc(sizeof(CoordsOfArray));
        scanf("%u%u%u", &A[i]->x, &A[i]->y, &A[i]->c);
    }
    for (i = 0; i < M; i++)
    {
        R[i] = (ArrayOfInterrogations)malloc(sizeof(InterrogationOfArray));
        scanf("%u%u%u%u", &R[i]->x1, &R[i]->y1, &R[i]->x2, &R[i]->y2);
    }
    check (A, R, N, M);
    return 0;
}
