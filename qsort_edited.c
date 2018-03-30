#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition_start(int a[], int l, int r)
{
	int pivot, i, j;
	pivot = a[l];
	i = l; j = r + 1;

	while (1)
	{
		do ++i; while (a[i] <= pivot && i <= r);
		do --j; while (a[j] % 2 != 0);
		if (i >= j)
			break;
		swap(a, i, j);
	}
	swap(a, l, j);
	return j;
}

int partition_dispair(int a[], int l, int r)
{
	int pivot, i, j;
	pivot = a[l];
	i = l; j = r + 1;

	while (1)
	{
		do ++i; while (a[i] <= pivot && i <= r);
		do --j; while (a[j] < pivot);
		if (i >= j)
			break;
		swap(a, i, j);
	}
	swap(a, l, j);
	return j;
}

int partition_pair(int a[], int l, int r)
{
	int pivot, i, j;
	pivot = a[l];
	i = l; j = r + 1;

	while (1)
	{
		do ++i; while (a[i] <= pivot && i <= r);
		do --j; while (a[j] > pivot);
		if (i >= j)
			break;
		swap(a, i, j);
	}
	swap(a, l, j);
	return j;
}

void quickSort_pair(int a[], int l, int r)
{
	int j;
	if (l < r)
	{
		j = partition_pair(a, l, r);
		quickSort_pair(a, l, j - 1);
		quickSort_pair(a, j + 1, r);
	}
}

void quickSort_dispair(int a[], int l, int r)
{
	int j;
	if (l < r)
	{
		j = partition_dispair(a, l, r);
		quickSort_dispair(a, l, j - 1);
		quickSort_dispair(a, j + 1, r);
	}
}

void firstSort(int a[], int l, int r)
{
	int j;
	if (l < r)
	{
		j = partition_start(a, l, r);
		firstSort(a, l, j - 1);
		firstSort(a, j + 1, r);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int *a = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	firstSort(a, 0, n - 1);
	i = 0;
	while (a[i])
	{
		if (a[i] % 2 != 0)
			break;
		i++;
	}
	quickSort_pair(a, 0, i - 1);
	quickSort_dispair(a, i, n - 1);
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}
