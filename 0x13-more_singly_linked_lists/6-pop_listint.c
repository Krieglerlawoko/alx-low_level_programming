#include "lists.h"
/**
 * pop_listint - funtion deletes node's head of linked list
 * @head: points to element first of the linked list
 *
 * Return: returns data that is inside deleted element or 0
 */

int pop_listint(listint_t **head)
{
	listint_t *j;
	int k;

	if (head || *head)
	{
		k = (*head)->n;
		j = (*head)->next;
		free(*head);
		*head = j;
	}
	else
	{
		return (0);
	}
	return (k);
}
