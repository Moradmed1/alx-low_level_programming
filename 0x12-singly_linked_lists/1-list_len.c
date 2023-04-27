#include "lists.h"

/**
 * list_len - returns number
 * @h: pointer
 *
 * Return: number
 */
 size_t list_len(const list_t *h)
 {
	size_t a =0;

	while (h)
	{
		a++;
		h = h->next;
	}
	return (a);
}
