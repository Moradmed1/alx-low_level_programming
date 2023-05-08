#include "main.h"

/**
 * create_file - creats file
 * @filename: file
 * @text_content: conte file
 *
 * Return: 1 pr -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nbr, rw;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";
	for (nbr = 0; text_content[nbr]; nbr++)
	rw = write(fd, text_content, nbr);

	if (rw == -1)
		return (-1);
	close(fd);
	return (1);
}
