#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _r - reallocates memory
 * for array to nodes
 * @list: old list
 * @size: size
 * @new: new node
 *
 * Return: pointer
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
	size_t j;

	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (j = 0; j < size - 1; j++)
		newlist[j] = list[j];
	newlist[j] = new;
	free(list);
	return (newlist);
}
/**
 * print_listint_safe - prints listint_
 * @head: pointer
 *
 * Return: number
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t j, m = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (j = 0; j < m; j++)
		{
			if (head == list[j])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (m);
			}
		}
		m++;
		list = _r(list, m, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (m);
}
