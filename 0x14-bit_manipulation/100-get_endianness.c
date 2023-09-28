#include "main.h"

/**
 *get_endianness - checks
 *
 *Return: 0 or 1
 */

int get_endianness(void)
{
	unsigned int y;
	char *m;

	y = 1;
	m = (char *) &y;

	return ((int)*m);
}
