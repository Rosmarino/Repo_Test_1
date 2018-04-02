#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int partition_pair_dispair(int A[], int p, int r)
{
	int x = A[p];
	int i = p;
	int j = r;
	while (i < j)
	{
		while (!A[i] % 2)
			i++;
		while (A[j] % 2 != 0)
			j--;
		if (i < j)
		{
			swap(A, i, j);
			i++;
		}
	}
	return j;
}

int partition_min_max(int A[], int p, int r)
{
	int x = A[p];
	int i = p;
	int j = r + 1;
	do
	{
		do
			i++;
		while (A[i] < x && i <= r);
		do
			j--;
		while (x < A[j]);
		if (i < j)
			swap(A, i, j);
		}
	while (i < j);
	A[p] = A[j];
	A[j] = x;
	return j;
}

int partition_max_min(int A[], int p, int r)
{
	int x = A[p];
	int i = p;
	int j = r;
	while (j > i)
	{
		while (A[j] <= x)
			j--;
		while (A[i] >= x)
			i++;
		if (i < j)
			swap(A, i, j);
	}
	A[p] = A[j];
	A[j] = x;
	return j;
}

void quicksortDispair(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition_max_min(A, p, r);
		quicksortDispair(A, p, q - 1);
		quicksortDispair(A, q + 1, r);
	}
}

void quicksortPair(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition_min_max(A, p, r);
		quicksortPair(A, p, q - 1);
		quicksortPair(A, q + 1, r);
	}
}

void quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition_pair_dispair(A, p, r);
		quicksortPair(A, p, q - 1);
		quicksortDispair(A, q + 1, r);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int *A = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	quicksort(A, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d\n", A[i]);
	return 0;
}
