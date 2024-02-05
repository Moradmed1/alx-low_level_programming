#include "lists.h"

/**
 * free_listint_safe - frees
 * @h: pointer
 *
 * Return: nbre
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int diff;
	listint_t *tmp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}
	*h = NULL;
		return (l);
}
