#include <stdio.h>
#include <stdlib.h>

int anagramma (unsigned char*s1 , unsigned char *s2)
{ 	
	int i=0;
	int *a = (int*) calloc(256,sizeof(int));
	int *b =(int*) calloc(256,sizeof(int));
	while (s1[i])
	{
		a[s1[i]]++;
		i++;
	}
	i=0;
	while (s2[i])
	{
		b[s2[i]]++;
		i++;
	}
	i=0;
	while (i<256)
	{
		if(a[i]!=b[i]) return 0;
		i++;
	}
	return 1;
}

int main ()
{
	unsigned char s1[256];
	unsigned char s2[256];
	scanf ("%s", s1);
	scanf ("%s", s2);
	printf ("%d\n", anagramma(s1,s2));
	return 0;
}
