#include "main.h"

/**
 * binary_to_uint - converts to int
 * @b: string
 *
 * Return: converted nbre
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int decim = 0;

		if (!b)
			return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		decim = 2 * decim + (b[j] - '0');
	}
	return (decim);
}
