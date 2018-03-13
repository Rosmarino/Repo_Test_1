#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int dim)
{
	int i;
	for (i = 1; i < dim; i++)
	{
		int j = i;
		int min = a[i];
		int trovato = 0;
		while (min < a[j - 1] && j > 0)
		{
			j--;
			a[j + 1] = a[j];
			trovato = 1;
		}
		if (j && trovato)
			a[j] = min;
		else if (trovato)
			a[0] = min;
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
	insertion_sort(a, n);
	return 0;
}
