#include <stdlib.h>
#include <stdio.h>
#include "function_pointers.h"
/**
 * main - print opcod
 * @argc: number args
 * @argv: qrrqy of args
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int b, j;
	char *arr;

	if (argc != 2)
		printf("Error\n"), exit(1);
	b = atoi(argv[1]);
	if (b < 0)
		printf("Error\n"), exit(2);

	arr = (char *)main;
	for (j = 0; j < b; j++)
	{
		if (j == b - 1)
		{
			printf("%02hhx\n", arr[j]);
			break;
		}
		printf("%02hhx ", arr[j]);
	}
	return (0);
}
