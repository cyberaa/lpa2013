/*
 *      A.c
 *      Copyright 2013 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[400][400];
int visited = 0;

void solve(int x, int y, int moves)
{
	if (moves == 0 || x > 400 || x < 0 || y > 400 || y < 0)
		return;
	
	if (table[x][y] == 0)
	{
		visited++;
		table[x][y] = 1;
		printf("%d %d\n", x-200, y-200);
	}
	
	solve(x+2, y+1, moves-1);
	solve(x+2, y-1, moves-1);
	solve(x+1, y+2, moves-1);
	solve(x+1, y-2, moves-1);
	solve(x-2, y+1, moves-1);
	solve(x-2, y-1, moves-1);
	solve(x-1, y+2, moves-1);
	solve(x-1, y-2, moves-1);
}

int main(int argc, char** argv)
{
	int nKnights;
	int x, y, moves;
	int i;
	
	while (scanf("%d", &nKnights) != EOF)
	{
		visited = 0;
		
		memset(table, 0, 400*400*sizeof(int));
		
		for (i=0 ; i<nKnights ; i++) {
			scanf("%d %d %d", &x, &y, &moves);
			x+=200;
			y+=200;
			moves++;
			solve(x, y, moves);
		}
		
		printf("%d\n", visited);
	}
	
	return 0;
}
