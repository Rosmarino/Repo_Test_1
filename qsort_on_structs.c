#include <stdio.h>
#include <stdlib.h>

typedef struct x_y
{
	int x;
	int y;
}coordinates;
typedef coordinates *coordinatesList;

int compare(const void *a, const void *b)
{
	const coordinates *a1 = *(const coordinates **)a;
	const coordinates *b1 = *(const coordinates **)b;
	if (a1->x > b1->x)
		return 1;
	else if (a1->x < b1->x)
		return (-1);
	else if (a1->x == b1->x)
	{
		if (a1->y < b1->y)
			return 1;
		else if (a1->y > b1->y)
			return (-1);
		else
			return 0;
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	coordinatesList *A = (coordinatesList*)malloc(n * sizeof(coordinates));
	for (i = 0; i < n; i++)
	{
		A[i] = (coordinatesList)malloc(sizeof(coordinates));
		scanf("%d%d", &A[i]->x, &A[i]->y);
	}
	qsort(A, n, sizeof(coordinates), compare);
	for (i = 0; i < n; i++)
		printf("%d %d\n", A[i]->x, A[i]->y);
	return 0;
}
