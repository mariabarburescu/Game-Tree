#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structura.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "bonus.h"

#define inf 9999

int main(int argc, char *argv[])
{
//Declar si deschid fisierele
	FILE *in;
	FILE *out;
	in = fopen(argv[2], "r");
	out = fopen(argv[3], "w");
//Declar variabilele si structurile de care am nevoie + le initializez
	int i, j, blank, alpha = -inf, beta = inf;
	char turn, pos, space, command[4];
	Coada *first, *last;
	initcoada(&first);
	initcoada(&last);
	node *head;
	tree *root;
	head = NULL;
	head = calloc(1,sizeof(node));
	root = NULL;
	root = calloc(1,sizeof(tree));
//Copiem comanda data ca si argument
	strcpy(command, argv[1]);

	if (command[2] == '1' || command[2] == '2')
	{
		//Citim ce jucator vom fi
		fscanf(in, "%c", &turn);
		fscanf(in, "%c", &space);	
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				//Citim starea intermediara a jocului
				fscanf(in, "%c", &pos);
				head -> A[i][j] = pos;
				fscanf(in, "%c", &space);
			}
		//Afisam starea care ni s-a dat
		if (command[2] == '1')
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
					if (j == 2)
						fprintf(out, "%c", head -> A[i][j]);
					else		
						fprintf(out, "%c ", head -> A[i][j]);
				fprintf(out, "\n");
			}
		//Memoram numarul de mutari pe care le putem face
		blank = blank_space(head -> A);
		//Generam toate mutarile
		generate(head, turn, blank, out, command);
	}
	//Rezolvarea pentru task-ul 2
	if (command[2] == '2')
	{
		if (turn == 'X')
			true_false(head, blank, turn, 'O', out);
		else
			true_false(head, blank, turn, 'X', out);
		show_c2(head, blank, out);
	}
	if (command[2] == '1')
		fprintf(out, "\n");
	if (command[2] == '3')
	{
		//Generam arborele pentru task-ul 3
		citire_task3(in, out, root, first, last);
		//Completam arborele conform algoritmului minimax
		maxmin(root, 1);
		//Adisam arborele
		show_c3(root, out);
	}
	if (command[1] == 'b')
	{
		citire_task3(in, out, root, first, last);
		bonus_function2(root, 1, &alpha, &beta);
		printf("ok\n");
		show_c3(root, out);
	}
	//Eliberam memoria
	if (command[2] == '1' || command[2] == '2')
	{
		eliberare_task1_2(head);
	}
	free(head);
	if (command[2] == '3')
	{
		eliberare_task3(root);
	}
	free(root);
	return 0;
}