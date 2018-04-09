#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
	char c[101];
	int dim;
}string_refer;
typedef string_refer *stringList;

int compare(const void *a, const void *b)
{
	const string_refer *a1 = *(const string_refer **)a;
	const string_refer *b1 = *(const string_refer **)b;
	if (a1->dim > b1->dim)
		return 1;
	else if (a1->dim < b1->dim)
		return (-1);
	else if (a1->dim == b1->dim)
	{
		if (strcmp(a1->c, b1->c) > 0)
			return 1;
		else if (strcmp(a1->c, b1->c) < 0)
			return (-1);
		else
			return 0;
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	stringList *A = (stringList*)malloc(n * sizeof(string_refer));
	for (i = 0; i < n; i++)
	{
		A[i] = (stringList)malloc(sizeof(string_refer));
		scanf("%s", &A[i]->c);
		A[i]->dim = strlen(A[i]->c);
	}
	qsort(A, n, sizeof(string_refer*), compare);
	for (i = 0; i < n; i++)
		printf("%s\n", A[i]->c);
	return 0;
}
