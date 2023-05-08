#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *c_buff(char *file);
void cl_file(int fd);

/**
 * c_buff - allocate 1024
 * @file: file
 *
 * Return: pointer
 */
char *c_buff(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * cl_file - close
 * @fd: desc
 */
void cl_file(int fd)
{
	int m;

	m = close(fd);

	if (m == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copie
 * @argc: nbre arg
 * @argv: pointer
 *
 * Return: 0
 *
 * Description: if arg exit 97
 */
int main(int argc, char *argv[])
{
	int fr, to, rw, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = c_buff(argv[2]);
	fr = open(argv[1], O_RDONLY);
	rw = read(fr, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	do {
		if (fr == -1 || rw == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(to, buffer, rw);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rw = read(fr, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (rw > 0);

	free(buffer);
	cl_file(to);
	return (0);

}

