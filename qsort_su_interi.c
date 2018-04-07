#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
	if (*(int*)a % 2 == 0 && *(int*)b % 2 == 1 || *(int*)a % 2 == 0 && *(int*)b % 2 == (-1))
		return (-1);
	else if (*(int*)a % 2 == 1 && *(int*)b % 2 == 0 || *(int*)a % 2 == (-1) && *(int*)b % 2 == 0)
		return 1;
	else if (*(int*)a % 2 == 0 && *(int*)b % 2 == 0)
		return (*(int*)a - *(int*)b);
	else if (*(int*)a % 2 == 1 && *(int*)b % 2 == 1  || *(int*)a % 2 == (-1) && *(int*)b % 2 == 1 || *(int*)a % 2 == 1 && *(int*)b % 2 == (-1) || *(int*)a % 2 == (-1) && *(int*)b % 2 == (-1))
		return (*(int*)b - *(int*)a);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int *A = (int *) malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	qsort(A, n, sizeof(int), compare);
	for (i = 0; i < n; i++)
		printf("%d\n", A[i]);
	return 0;
}
