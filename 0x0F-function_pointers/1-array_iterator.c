#include "function_pointers.h"
/**
 * array_iterator - maps an array throuth a func pointer
 * @array: array
 * @size: the array size
 * @action: fuction pointer
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

