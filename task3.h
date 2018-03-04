#ifndef task3
#define task3

#include "structura.h"

void task3_function(tree *root, Coada **first, Coada **last, char *read, int level)
{
	int i, j, nr;
	char *token, p;
	token = strtok(read, " \n");
	while (token != NULL)
	{
		root = (*first) -> celula;
		dequeue(first, last);
		root -> nivel = level - 1;
		root -> next = calloc(root -> sons, sizeof(tree));
		for (i = 0; i < root -> sons; i++)
		{
			root -> next[i] = NULL;
			root -> next[i] = calloc(1, sizeof(tree));
			root -> next[i] -> nivel = level;
			p = token[0];
			memmove(token, token + 1, strlen(token));
			token[strlen(token)-1] = '\0';
			nr = atoi(token);
			if (p == '(')
			{
				root -> next[i] -> sons = nr;
				enqueue(first, last, root -> next[i]);
			}
			if (p == '[')
			{
				root -> next[i] -> val = nr;
				root -> next[i] -> sons = 0;
			}
			token = strtok(NULL, " \n");
		}
	}
}

void citire_task3(FILE *in, FILE *out, tree *root, Coada *first, Coada *last)
{
	char space, *read;
	int i, n, size;
	size_t length;
	length = 400000;
	fscanf(in, "%d", &n);
	fscanf(in, "%c", &space);
	read = calloc(400000, sizeof(char));
	getline(&read, &length, in);
	memmove(read, read + 1, strlen(read));
	read[strlen(read)-2] = '\0';
	size = atoi(read);
	root -> nivel = 0;
	root -> sons = size;
	enqueue(&first, &last, root);
	for (i = 1; i < n; i++)
	{
		getline(&read, &length, in);
		read[strlen(read)] = '\0';
		task3_function(root, &first, &last, read, i);
	}
	free(read);
}

void show_c3(tree *root, FILE  *out)
{
	int i;
	for (i = 0; i < root -> nivel; i++)
		fprintf(out, "\t");
	fprintf(out, "%d\n", root -> val);
	for (i = 0; i < root -> sons; i++)
	{
		show_c3(root -> next[i], out);
	}
}

void maxmin(tree *root, int ok)
{
	int i;
	if (root -> sons == 0)
		return;
	for (i = 0; i < root -> sons; i++)
	{
		if (ok == 1)
			maxmin(root -> next[i], 0);
		else
			maxmin(root -> next[i], 1);
	}
	root -> val = root -> next[0] -> val;
	for (i = 0; i < root -> sons; i++)
	{
		if (ok == 0)
		{
			if (root -> val > root -> next[i] -> val)
				root -> val = root -> next[i] -> val;
		}
		else
			if (root -> val < root -> next[i] -> val)
				root -> val = root -> next[i] -> val;
	}
}

#endif