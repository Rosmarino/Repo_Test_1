#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition (int A[], int p, int r)
{
    int x = A[r]; // Pivot of the last element
    int i = p - 1; // Increases in the cycle
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(&A[i], &A[j]); // Swap the elements by their addresses
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1; // Returns the new pivot
}

void quicksort (int A[], int p, int r)
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
    int *A = (int*) malloc (n * sizeof(int)); // Array of n elements
    for (i = 0; i < n; i++) // Fills the array
        scanf("%d", &A[i]);
    quicksort(A, 0, n - 1); // Quicksort call
    for (i = 0; i < n; i++) // Prints the array
        printf("%d\n", A[i]);
    return 0;
}
