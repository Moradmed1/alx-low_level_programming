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
int main(int argc, char **argv)
{
	char *p = (char *)main;
	int b;

	if (argc != 2)
		printf("Error\n"), exit(1);
	b = atoi(argv[1]);
	if (b < 0)
		printf("Error\n"), exit(2);

	while (b--)
		printf("%2hhx%s", *p++, b ? " " : "\n");
	return (0);
}
