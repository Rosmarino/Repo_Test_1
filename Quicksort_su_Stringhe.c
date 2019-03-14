#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b)
{
    char c[101];
    strcpy(c, *a);
    strcpy(*a, *b);
    strcpy(*b, c);
}

int partition (char *A[], int p, int r)
{
    char x[101]; // Pivot of the last element
    strcpy(x, A[r]);
    int i = p - 1; // Increases in the cycle
    for (int j = p; j < r; j++)
    {
        if (strcmp(A[j], x) <= 0)
        {
            i++;
            swap(&A[i], &A[j]); // Swap the elements by their addresses
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1; // Returns the new pivot
}

void quicksort (char *A[], int p, int r)
{
    if (p < r) // If there are elements left
    {
        int q = partition(A, p, r); // Calls partition
        quicksort(A, p, q - 1); // Recursively calls quicksort on the first n/2 side
        quicksort(A, q + 1, r); // Recursively calls quicksort on the second n/2 side
    }
}

int main ()
{
    int n = 0, i = 0;
    scanf("%d", &n); // Number of elements
    char **A = (char**) malloc (n * sizeof(char*)); // Multi-dimentional array of strings
    for (i = 0; i < n; i++) // Fills the array
    {
        A[i] = (char*) malloc (101 * sizeof(char)); // String of 100 char in the 'i' position
        scanf("%s", A[i]);
    }
    quicksort(A, 0, n - 1); // Quicksort call
    for (i = 0; i < n; i++) // Prints the array
        printf("%s\n", A[i]);
    return 0;
}
