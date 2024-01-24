#include "function_pointers.h"

/**
 * print_name - prints name
 * @name: the name
 * @f: poiter to function
 * Return: noting
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
