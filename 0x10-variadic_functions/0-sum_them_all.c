#include "variadic_functions.h"

/**
 * sum_them_all - sum of all its para.
 * @an: number of paramters
 * @a...: var number of paramters to calc the sum
 *
 * Return: if n == 0 - 0.
 * otherwise - the sum of all para.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int j, sum = 0;

	va_start(ap, n);
	for (j = 0; j < n; j++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
