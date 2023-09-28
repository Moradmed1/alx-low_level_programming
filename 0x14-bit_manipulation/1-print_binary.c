#include "main.h"

/**
 * print_binary - prints binary
 * @n: nbre
 */
void print_binary(unsigned long int n)
{
	int j, m = 0;
	unsigned long int current;

	for (j = 63; j >= 0; j--)
	{
		current = n >> j;
		if (current & 1)
		{
			_putchar('1');
			m++;
		}
		else if (m)
			_putchar('0');
	}
	if (!m)
		_putchar('0');
}
