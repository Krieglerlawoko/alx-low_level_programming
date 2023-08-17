#include "lists.h"

/**
 * delete_nodeint_at_index - function removes a node in a linked list
 * @head: points to the first member of the list
 * @index: reps the index node to delete
 *
 * Return: 1 for success or -1 for fail
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j = 0;
	listint_t *cur = NULL;
	listint_t *k = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(k);
		return (1);
	}
	while (j < index - 1)
	{
		if (k || (k->next))
		{
			k = k->next;
			j++;
		}
		else
		{
			return (-1);
		}
	}
	cur = k->next;
	k->next = cur->next;
	free(cur);

	return (1);
}

