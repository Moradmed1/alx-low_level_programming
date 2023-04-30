#include "lists.h"

/**
 * add_nodeint - adds a node
 * @head: address
 * @n: str filed
 *
 * Return: pointer of node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *m;
	m = malloc(sizeof(listint_t));

	if (!m)
		return (NULL);
	
	m->n = n;
	m->next = *head;
	*head = m;

	return (m);
}
