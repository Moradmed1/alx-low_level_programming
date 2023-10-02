#include "main.h"
#include <stdlib.h>

/**
 *read_textfile - Read lire txt print to stdout
 * @filename: file
 * @letters:nbre lettre to be read
 * Return: nbrw or 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd, nbrw, m;

	/* open file ronly, if filed return -1*/
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

	/* allocated tompon to stock data*/
	buff = malloc(sizeof(char) * letters);

	/*read data on buffer*/
	m = read(fd, buff, letters);

	/*write data on stdout*/
	nbrw = write(STDOUT_FILENO, buff, m);
	/*libere mem*/
	free(buff);
	/*close descripteur file*/
	close(fd);
	return (nbrw);
}
