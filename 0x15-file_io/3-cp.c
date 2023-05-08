#include "main.h"
#include <stdio.h>

/**
 * error_file - checks opened
 * @file_from: file
 * @file_to: file
 * @argv: arg
 * Return: qvoid
 */

void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't wite to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - chech code
 * @argc: nbre arg
 * @argv: arg vec
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int from, to, err_cl;
	ssize_t nchars, nbwr;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(from, to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(from, buff, 1024);
		if (nchars == -1)
			error_file(-1, 0, argv);
		nbwr = write(to, buff, nchars);
		if (nbwr == -1)
			error_file(0, -1, argv);
	}

	err_cl = close(from);
	if (err_cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}

	err_cl = close(to);
	if (err_cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	return (0);
}
