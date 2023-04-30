#include "lists.h"

/**
 * add_nodeint_end - adds node
 * @head: pointer
 * @n: nuber used
 *
 * Return: adress new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_nod;
	listint_t *curs = *head;

	new_nod = malloc(sizeof(listint_t));
	if (new_nod != NULL)
	{
		new_nod->n = n;
		new_nod->next = NULL;
	}
	else
		return (NULL);
	if (curs != NULL)
	{
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = new_nod;
	}
	else
		*head = new_nod;
	return (new_nod);
}
