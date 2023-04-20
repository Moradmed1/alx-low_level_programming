#include "variadic_functions.h"

/**
 * sum_them_all - sum of all its para.
 * @n: number of paramters
 * @a...: var number of paramters to calc the sum
 *
 * Return: if n == 0 - 0.
 * otherwise - the sum of all para.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ar;
	int j = n, sum = 0;

	if (!n)
		return (0);
	va_start(ar, n);
	while (j--)
		sum += va_arg(ar, int);

	va_end(ar);

	return (sum);
}
