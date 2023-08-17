#include "lists.h"

/**
 * free_listint2 - a function that frees linked lists
 * @head: points to the list to work on
 */

void free_listint2(listint_t **head)
{
	listint_t *k;

	if (head)
	{
		while (*head)
		{
			k = (*head)->next;
			free(*head);
			*head = k;
		}
	}
	else
	{
		return;
	}
	*head = NULL;
}

