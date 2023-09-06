#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *ct_buffer(char *file);
void cl_file(int fd);

/**
* ct_buffer - Alloc 1024 bytes for a buffer.
* @file: name file buffer  for.
*
* Return: pointer to the
* buffer.
*/
char *ct_buffer(char *file)
{
char *buf;

buf = malloc(sizeof(char) * 1024);

if (buf == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buf);
}

/**
* cl_file - Closes file descriptors.
* @fd: file descriptor to be closed.
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
* main - Cp conts  file to another file.
* @argc: Number of argumentsm.
* @argv:  array of pointers s.
*
* Return: 0 on success.
*
* Description: If  arg count is incorrect - exit code 97.
* If file_from  not exist not read - exit code 98.
* If file_to not created or written to - exit code 99.
* If file cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
int from, to, rr, ww;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buf = ct_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
rr = read(from, buf, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || rr == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buf);
exit(98);
}

ww = write(to, buf, rr);
if (to == -1 || ww == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buf);
exit(99);
}

rr = read(from, buf, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (rr > 0);

free(buf);
cl_file(from);
cl_file(to);

return (0);
}
