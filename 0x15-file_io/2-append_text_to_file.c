#include "main.h"

/**
*append_text_to_file - append
*@filename: pointer
*@text_content: string
*
*Return: -1 or NULL
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int m,rw, nbr = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (nbr = 0; text_content[nbr];)
			nbr++;
	}
	m = open(filename, O_WRONLY | O_APPEND);
	rw = write(m, text_content, nbr);

	if (m == -1 || rw ==-1)
		return (-1);

	close(m);
	return (1);
}
