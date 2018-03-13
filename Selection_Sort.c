#include <stdio.h>
#include <stdlib.h>

void sel_sort(int a[], int dim) 
{
	int i, j, min;
	double t;
	for (i = 0; i < dim - 1; i++) 
	{
		min = i;
		for (j = i + 1; j < dim; j++) 
		{
			if (a[j] < a[min]) 
				min = j;
		}
		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
	for (i = 0; i < dim; i++)
		printf("%d\n", a[i]);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int *a = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sel_sort(a, n);
	return 0;
}
