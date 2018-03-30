#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int a[], int dim)
{
	int i = 0, j = 1, key;
	while (j < dim)
	{
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
		j++;
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int *a = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Insertion_Sort(a, n);
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}
