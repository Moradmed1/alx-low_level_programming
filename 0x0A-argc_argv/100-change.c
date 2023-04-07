#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
* main-prints the minimum number of coin
* make change for an amount of money
* @argc: number of arguments
* @argv: array of arguments
*
*/
int main(int argc, char *argv[])
{
	int cents;
	int count = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	while (cents > 0)
	{
		if (cents >= 25)
		{
			cents = cents - 25;		
		}
		else if (cents >= 10)
		{
			cents = cents - 10;
		}
		else if (cents >= 5)
		{
			cents = cents - 5;
		}
		else if (cents >= 2)
		{
			cents = cents - 2;
		}
		else if (cents >= 1)
		{
			cents = cents - 10;
		}
	count++;
	}

	printf("%d\n", count);
	return (0);
}
