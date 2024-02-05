#include "stdio.h"
#include "lists.h"

/**
 * sum_listint - calculay=te sum
 * @head: pointer
 * Return: sum
 * or 0
 */
int sum_listint(listint_t *head)
{
	int add1;

	add1 = 0;

	while (head)
	{
		add1 += head->n;
		head = head->next;
	}
	return (add1);
}
