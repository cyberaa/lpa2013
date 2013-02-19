/*
 *      A.c
 *      Copyright 2013 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

char matrix[MAX_SIZE][MAX_SIZE];
int line, col;

int maze(int r, int c)
{
	int aux;

	if(r == 0 && matrix[r][c] != '#')
	{
		printf("(%d,%d)", r+1, c+1);
		return 1;
	}

	if(matrix[r][c] == '/')
	{
		matrix[r][c]='#';

		if((r-1 >= 0 && c+1 < col) && (matrix[r-1][c+1] == '/' || matrix[r-1][c+1] == '|'))
		{
			aux = maze(r-1, c+1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1,c+1);
				return 1;
			}
		}

		if(r-1 >= 0 && matrix[r-1][c] == '\\')
		{
			aux = maze(r-1, c);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1,c+1);
				return 1;
			}
		}

		if(c+1 < col && matrix[r][c+1] == '\\')
		{
			aux = maze(r, c+1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1,c+1);
				return 1;
			}
		}

		if(c-1 >= 0 && matrix[r][c-1] == '\\')
		{
			aux = maze(r, c-1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}
	}

	else if(matrix[r][c] == '|')
	{

		matrix[r][c]='#';
		if(c-1 >= 0 && matrix[r-1][c] == '|')
		{
			aux = maze(r-1, c);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}

		if((r-1 >= 0 && c+1 < col) && matrix[r-1][c+1] == '/')
		{
			aux = maze(r-1, c+1);
			if(aux == 1){
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}

		if((r-1 >= 0 && c-1 >= 0) && matrix[r-1][c-1] == '\\')
		{	
			aux = maze(r-1, c-1);
			if(aux == 1){
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}

	}

	else if(matrix[r][c] == '\\')
	{
		matrix[r][c]='#';

		if((r-1 >= 0 && c-1 >= 0) && (matrix[r-1][c-1] == '\\' || matrix[r-1][c-1] == '|'))
		{
			aux = maze(r-1, c-1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}

		if(r-1 >= 0 && matrix[r-1][c] == '/')
		{
			aux = maze(r-1, c);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}
		
		if(c+1 < col && matrix[r][c+1] == '/')
		{
			aux = maze(r, c+1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}
		
		if(c-1 >= 0 && matrix[r][c-1] == '/')
		{
			aux = maze(r, c-1);
			if(aux == 1)
			{
				printf(",(%d,%d)", r+1, c+1);
				return 1;
			}
		}
	}
	return 0;	
}

int main(int argc, char **argv)
{
	int i, end;

	while(scanf("%d %d", &line, &col) != EOF)
	{
		end = 0;

		for(i = 0; i < line; i++)
			scanf("%s",matrix[i]);
		
		for(i = 0; i < col && end == 0; i++)
			if(matrix[line-1][i] != '#')
				end=maze(line-1, i);

		if(!end)
			printf("No Path!");

		printf("\n");
	}

	return 0;
}
