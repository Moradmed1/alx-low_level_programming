#include "lists.h"

/**
 * pop_listint - deletes head node
 * @head: pointer
 * Return: head
 * or 0 - if linked
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	tmp = *head;

	if (tmp == NULL)
	return (0);

	*head = tmp->next;
	n = tmp->n;
	free(tmp);
	return (n);
}
