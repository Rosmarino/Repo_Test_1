#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int distribuzione(char *a[], int sx, int px, int dx) 
{ 
	int j, i = sx - 1;
	char pivot[101], swap[101];
	strcpy(pivot, a[dx]);
	for (j = sx; j <= dx - 1; j++)
	{
		if (strcmp(a[j], pivot) <= 0)
		{
			i++;
			strcpy(swap, a[i]);
			strcpy(a[i], a[j]);
			strcpy(a[j], swap);
		}
	}
	strcpy(swap, a[i + 1]);
	strcpy(a[i + 1], a[dx]);
	strcpy(a[dx], swap);
	return i + 1;
}

void quicksort(char *a[], int sx, int dx ) 
{ 
	int perno, pivot;
	if(sx < dx) 
	{
		pivot = (sx + dx)/ 2;
		perno = distribuzione(a, sx, pivot, dx);
		quicksort(a, sx, perno - 1);
		quicksort(a, perno + 1, dx);   
	}
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
	quicksort(a, 0, n-1);
	for(i = 0; i < n; i++ ) 
		printf("%s\n", a[i]);	
	return 0;
}
