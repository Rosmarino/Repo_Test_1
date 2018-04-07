#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) 
{
	char **a1 = (char **)a;
	char **b1 = (char **)b;
	return strcmp(*b1, *a1);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	char ** C = malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) 
	{
		C[i] = malloc(101 * sizeof(char));
		scanf("%s", C[i]);
	}
	qsort(C, n, sizeof(char*), compare);
	for (i = 0; i < n; i++)
		printf("%s\n", C[i]);
	return 0;
}
