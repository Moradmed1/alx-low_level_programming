#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: type of arguments
 *
 */

void print_all(const char * const format, ...)
{
	int j = 0;
	char *ptr, *separ = "";

	va_list ap;

	va_start(ap, format);

	if (format)
	{
		while (format[j])
		{
			switch (format[j])
			{
				case 'c':
					printf("%s%c", separ, va_arg(ap, int));
					break;
				case 'i':
					printf("%s%d", separ, va_arg(ap, int));
					break;
				case 'f':
					printf("%s%f", separ, va_arg(ap, double));
					break;
				case 's':
					ptr = va_arg(ap, char *);
					if (!ptr)
						ptr = "(nil)";
					printf("%s%s", separ, ptr);
					break;
				default:
					j++;
					continue;

			}
			separ = ", ";
			j++;
		}
	}
	printf("\n");
	va_end(ap);
}
