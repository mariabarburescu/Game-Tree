#ifndef task2
#define task2

#include "structura.h"

void show_c2(node *head, int blank, FILE *out)
{
	int i, n;
	n = blank_space(head -> A);
	for (i = 0; i < blank - n; i++)
		fprintf(out, "\t");
	fprintf(out, "%c\n", head -> val);
	if (win(head -> A) == 1)
		return;
	for (i = 0; i < n; i++)
		show_c2(head -> next[i], blank, out);
}

void true_false(node *head, int blank, char turn, char move, FILE *out)
{
	int n = blank_space(head -> A);
	int i;
	if (win(head -> A) == 1)
	{
		if (turn == move)
		{
			head -> val = 'T';
			printf("%c %c\n", turn, move);
			printf("T\n");
			return;
		}
		else
		{
			head -> val = 'F';
			printf("%c %c\n", turn, move);
			printf("F\n");
			return;
		}
	}
	if (n == 0)
	{
		head -> val = 'F';
		printf("%c %c\n", turn, move);
		printf("F\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (move == 'X')
			true_false(head -> next[i], blank, turn, 'O', out);
		else
			true_false(head -> next[i], blank, turn, 'X', out);
	}
	if (turn == move)
	{
		head -> val = 'T';
		for (i = 0; i < n; i++)
			if (head -> next[i] -> val == 'F')
			{
				head -> val = 'F';
				printf("%c %c\n", turn, move);
				printf("T\n");
				return;
			}
	}
	else
	{
		head -> val = 'F';
		for (i = 0; i < n; i++)
			if (head -> next[i] -> val == 'T')
			{
				head -> val = 'T';
				printf("%c %c\n", turn, move);
				printf("F\n");
				return;
			}
	}
}

#endif