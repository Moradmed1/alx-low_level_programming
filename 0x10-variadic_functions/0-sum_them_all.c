#include "variadic_functions.h"

/**
 * sum_them_all - sum of all its para.
 * @n: number of paramters
 * @a...: var number of paramters to calc the sum
 *
 * Return: sum.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	int j = n, sum = 0;

	if (!n)
		return (0);
	va_start(ap, n);
	while (j--)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}
