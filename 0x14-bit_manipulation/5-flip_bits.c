#include "main.h"
/**
 * flip_bits - returns nbre bit
 * @n: nbre one
 * @m: nbre two
 *
 * Return: nbre bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbre;

	for (nbre = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbre++;
	}
	return (nbre) ;
}
