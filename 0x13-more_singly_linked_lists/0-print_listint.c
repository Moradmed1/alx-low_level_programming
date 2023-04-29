#include "lists.h"
/**
 * print_listint - print elt of linked list
 * @h: linked list
 *
 * Return: number nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t m = 0;

	while (h)
	{
		printf("%d\n", h->n);
		m++;
		h = h->next;
	}

	return (m);
}
