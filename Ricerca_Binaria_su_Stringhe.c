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
}

int ric_bin (char *a[], int dim, char *s)
{
	int p, u, m;
	p = 0;
	u = dim - 1;
	while (p <= u) 
	{
		m = (p + u) / 2;
		if (strcmp(a[m], s) == 0)
			return m;
		if (strcmp(a[m], s) < 0)
			p = m + 1;
		else
			u = m - 1;
	}
	return -1;
}

int main()
{
	int i, n, check;
	char s[101];
	scanf("%d", &n);
	char **a;
	a = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		a[i] = (char *)malloc(101 * sizeof(char));
		scanf("%s", a[i]);
	}
	ins_sort(a, n);
	scanf("%d", &check);
	while (check == 1)
	{
		scanf("%s", s);
		printf("%d\n", ric_bin(a, n, s));
		scanf("%d", &check);
	}
	return 0;
}
