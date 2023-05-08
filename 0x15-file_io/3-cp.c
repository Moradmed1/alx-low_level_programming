#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocate 1024 for buffer
 * @file: file name
 *
 * Return: pointer to all buffer
 */
char *create_buffer(char *file)
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
 * close_file - close file descriptors
 * @fd: desc to be closed
 */
void close_file(int fd)
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
 * main - copie conte file to another
 * @argc: nbre arg
 * @argv: pointer array
 *
 * Return: 0.
 *
 * Description: if arg incorrect exit 97
 * can't read - exit code 98
 * can't be creaated - exite code 99
 * can't be closed - exit code 100
 */
int main(int argc, char *argv[])
{
	int from, to, rr, ww;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rr = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	do {
		if (from == -1 || rr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		ww = write(to, buffer, rr);
		if (to == -1 || ww == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rr = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

		} while (rr > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

