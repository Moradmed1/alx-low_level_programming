#include <stdio.h>

/**
* main - prints the name of the  program
* @argc: argument count
* @argv: argument vector
* Return: 0 if true, 1 if false
*/
int main(int argc, char *argv[])
{
	int i;
	int tot = 0;

	if (argc == 1)
	{
		printf("0\n");
	}
	else
	{
		for (i = 1 ; i < argc ; i++)
		{
		if (!atoi(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		else
			tot = tot + atoi(argv[i]);
		}
		printf("%d\n", tot);
	}
	return (0);
}
