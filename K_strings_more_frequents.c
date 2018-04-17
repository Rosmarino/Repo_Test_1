#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	char **a1 = (char **)a;
	char **b1 = (char **)b;
	return strcmp(*a1, *b1);
}

int freq(char *A[], int n, int k)
{
	char **B = (char **)malloc(k * sizeof(char *));
	int i, j, counter, longest, z = 0, found, index = 0, check;
	for (int f = 0; f < n - 2 && z < k; f++)
	{
		longest = 0;
		for (i = f; i < n - 2; i++)
		{
			counter = 0;
			j = 0;
			found = 0;
			while (!found && i < n - 2)
			{
				check = i;
				for (j = 0; j < z; j++)
					if (strcmp(A[i], B[j]) == 0)
						i++;
				if (check == i)
					found = 1;
			}
			for (j = i + 1; j < n; j++)
				if (strcmp(A[i], A[j]) == 0)
					counter++;
			if (counter > longest)
			{
				longest = counter;
				index = i;
			}
		}
		B[z] = (char *)malloc(101 * sizeof(char));
		strcpy(B[z], A[index]);
		z++;
	}
	qsort(B, k, sizeof(char*), compare);
	for (i = 0; i < k; i++)
		printf("%s\n", B[i]);
}

int main()
{
	int n, k, i;
	scanf("%d", &n);
	scanf("%d", &k);
	char **A = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		A[i] = (char *)malloc(101 * sizeof(char));
		scanf("%s", A[i]);
	}
	freq(A, n, k);
	return 0;
}
