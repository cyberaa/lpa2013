/*
 *      B.c
 *      Copyright 2013 João Ferreira <joao@void>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 128

char str [MAX_SIZE], aux[MAX_SIZE];

int solve()
{
	int i, j = -1, size = strlen(str);

	for(i = 0; i < size; i++)
	{
		if(j >= 0 && ((aux[j] == '(' && str[i] == ')') || (aux[j] == '[' && str[i] == ']')))
		{
			aux[j]='\0';
			j--;
		}
		else
		{
			j++;
			aux[j]=str[i];
		}
	}

	if(j >= 0)
		return 0;
	else
		return 1;
}

int main(int argc, char** argv)
{
	int tests, i;

	scanf("%d", &tests);

	for (i = 0; i < tests; i++)
	{
		scanf("%s", str);
		if(solve())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
