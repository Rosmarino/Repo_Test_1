#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ins_sort(char *a[], int n)
{
	int i, j;
	char min[101];
	for(i = 0; i < n; i ++)
	{
		strcpy(min, a[i]);
		j = i - 1;
		while (j >= 0 && strcmp(min, a[j]) < 0)
		{
			strcpy(a[j + 1], a[j]);
			j--;
		}
		strcpy(a[j + 1], min);
	}
	for (i = 0; i < n; i++)
		printf("%s\n", a[i]);
}

int main()
{
	int i, n;
	scanf("%d", &n);
	char **a;
	a = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		a[i] = (char *)malloc(101 * sizeof(char));
		scanf("%s", a[i]);
	}
	ins_sort(a, n);
	return 0;
}
