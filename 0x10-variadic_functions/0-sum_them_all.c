#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sums variable
 * @n: the number arguments
 * @...: integers to sum
 *
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int som = 0, j = n;
	va_list ap;

	if (!n)
		return (0);
	va_start(ap, n);
	while (j--)
		som += va_arg(ap, int);
	va_end(ap);
	return (som);
}
