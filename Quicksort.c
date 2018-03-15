#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int distribuzione(int a[], int sx, int px, int dx) 
{ 
	int swap, j, pivot = a[dx], i = sx - 1;
	for (j = sx; j <= dx - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap = a[i];
			a[i] = a[j];
			a[j] = swap;
		}
	}
	swap = a[i + 1];
	a[i + 1] = a[dx];
	a[dx] = swap;
	return i + 1;
}

void quicksort( int a[], int sx, int dx ) 
{ 
	int perno, pivot;
	if(sx < dx) 
	{
		pivot = (sx + dx)/ 2;
		perno = distribuzione(a, sx, pivot, dx);
		quicksort(a, sx, perno - 1);
		quicksort(a, perno + 1, dx);   
	}
}

int legge(int **a, int *len) 
{
	int i;
	scanf("%d", len);
	if(*len <= 0)
		return 1;
	*a = (int *) malloc(*len * sizeof(int));
	if(*a == NULL) 
		return 1;
	for( i = 0; i < *len; i++ ) 
		scanf("%d", (*a) + i); 
	return 0;
}

int main() 
{
	int i, n, *A;
	if( legge(&A, &n))
		return 1;
	srand(time(NULL));
	quicksort(A, 0, n-1);
	for( i = 0; i < n; i++ ) 
		printf("%d ", A[i]);	
	return 0;
}
