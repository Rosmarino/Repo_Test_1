#include <stdio.h>
#include <stdlib.h>

struct TreeN {
	int key;
	struct TreeN* sx;
	struct TreeN* dx;
};

typedef struct TreeN NodeTree;
typedef NodeTree *Tree;

void inserimento (Tree* T, NodeTree* nt)
{
	NodeTree *x;
	x = *T;
	NodeTree *y = NULL;
	while (x != NULL)
	{
		y = x;
		if (nt->key < x->key)
			x = x->sx;
		else
			x = x->dx;
	}
	if (y == NULL)
		*T = nt;
	else
	{
		if (y->key > nt->key)
			y->sx = nt;
		else
			y->dx = nt;
	}
}

struct Vis {
	int dx;
	int sx;
};

struct Vis visita (NodeTree *u)
{
	struct Vis result;
	result.dx = 0;
	result.sx = 0;
	if (u == NULL)
		return result;
	int sx = visita (u->sx).sx;
	int dx = visita (u->dx).dx;
	if (sx > dx)
		printf("%d\r\n", u->key);
	result.sx = sx + 1;
	result.dx = dx + 1;
	return result;
}

int main(int argc, char **argv)
{
	int n, key;
	Tree *T = malloc (sizeof(NodeTree*));;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		NodeTree* u = malloc(sizeof(NodeTree));
		scanf (" %d", &key);
		u->key = key;
		inserimento(T, u);
	}
	visita (*T);
	return 0;
}

