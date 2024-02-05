#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - finds loop
 *
 * @head: linked
 *
 * Return: adress or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pt, *fin;

	if (head == NULL)
		return (NULL);
	for (fin = head->next; fin != NULL; fin = fin->next)
	{
		if (fin == fin->next)
			return (fin);
		for (pt = head; pt != fin; pt = pt->next)
			if (pt == fin->next)
			return (fin->next);

	}
	return (NULL);
}
