#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @file: name  file buffer  for.
*
* Return: A pointer to the 
*  buffer.
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
* close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
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
* main - Copies  contents  file to another file.
* @argc: The number of argumentsm.
* @argv: An array of pointers s.
*
* Return: 0 on success.
*
* Description: If the argument count is incorrect - exit code 97.
* If file_from  not exist not read - exit code 98.
* If file_to not created or written to - exit code 99.
* If file cannot be closed - exit code 100.
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
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

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
