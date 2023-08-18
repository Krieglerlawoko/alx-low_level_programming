#include "lists.h"

/**
 * reverse_listint - function that reverses a list
 * @head: points to very first node in list
 *
 * Return: returns pointer of first node in new created list
 */

listint_t *reverse_listint(listint_t **head)
{

	listint_t *next = NULL;
	listint_t *j = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = j;
		j = *head;
		*head = next;
	}
	*head = j;
	return (*head);
}

