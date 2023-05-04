#include "main.h"

/**
 * get_bit - returns value bit at index
 * @n: nbre
 * @index: index
 *
 * Return: value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int val;

	if (index > 63)
		return (-1);

	val = (n >> index) & 1;
	return (val);
}
