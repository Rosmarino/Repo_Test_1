#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _anagram
{
    char info[20];
    char anagram[20];
}AnagramOfChar;
typedef AnagramOfChar *CharOfAnagram;

int compare_anagram(const void *a, const void *b) 
{
    const AnagramOfChar *a1 = *(const AnagramOfChar **)a;
    const AnagramOfChar *b1 = *(const AnagramOfChar **)b;
    if (strcmp(a1->anagram, b1->anagram) == 0) // Same master anagram
        return (strcmp(a1->info, b1->info));
    else
        return (strcmp(a1->anagram, b1->anagram));
}

int compare_char(const void *a, const void *b) 
{
    char *a1 = (char*)a;
    char *b1 = (char*)b;
    return (*a1 - *b1);
}

int main ()
{
    int N = 0, i = 0;
    scanf("%d", &N);
    CharOfAnagram *A = (CharOfAnagram*) malloc (N * sizeof(AnagramOfChar*));
    for (i = 0; i < N; i++)
    {
        A[i] = (CharOfAnagram) malloc (sizeof (AnagramOfChar));
        scanf("%s", A[i]->info);
    }
    for(i = 0; i < N; i++) // Master anagram
    {
        char copy[20];
        strcpy(copy, A[i]->info);
        qsort(copy, strlen(copy), sizeof(char), compare_char);
        strcpy(A[i]->anagram, copy);
    }
    qsort(A, N, sizeof(char**), compare_anagram);
    i = 0;
    while(i < N)
    {
        printf("%s ", A[i]->info);
        i++;
        while (i < N && strcmp(A[i]->anagram, A[i - 1]->anagram) == 0)
        {
            printf("%s ", A[i]->info);
            i++;
        }
        if (i < N)
            printf("\n");
    }
    return 0;
}
