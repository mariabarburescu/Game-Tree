#ifndef task1
#define task1

#include "structura.h"

//Functie de afisare a unei matrice din arbore
void show_c1(char A[3][3], int n, FILE *out)
{
	int i, j, k;
	fprintf(out, "\n");
	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < n; k++)
			fprintf(out, "\t");
		for (j = 0; j < 3; j++)
			if (j == 2)
				fprintf(out, "%c", A[i][j]);
			else
				fprintf(out, "%c ", A[i][j]);
		fprintf(out, "\n");
	}
}

void generate(node *head, char turn, int blank, FILE *out, char command[4])
{
	char C[9][9];
	int n, i, j, k;
	if (win(head -> A) == 1)
		return;
	n = blank_space(head -> A);
	if (n == 0)
		return;
	head -> next = calloc(n,sizeof(node*));
	for (i = 0; i < n; i++)
	{
		head -> next[i]=NULL;
		head -> next[i] = (node*)calloc(1,sizeof(node));
	}
	if (win(head -> A) == 0)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				C[i][j] = head -> A[i][j];
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					head -> next[k] -> A[i][j] = head -> A[i][j];
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
					if (C[i][j] == '-')
					{	head -> next[k] -> A[i][j] = turn;
						C[i][j] = turn;
						if (command[2] == '1')
							show_c1(head -> next[k] -> A, blank-blank_space(head -> next[k] -> A), out);
						j=3;
						i=3;
						if (turn == 'O')
							generate(head -> next[k], 'X', blank, out, command);
						else
							generate(head -> next[k], 'O', blank, out, command);
					}
			}
		}
	}
}

#endif