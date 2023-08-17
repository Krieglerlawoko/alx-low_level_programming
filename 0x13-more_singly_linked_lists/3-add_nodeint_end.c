#include "lists.h"

/**
 * add_nodeint_end - a function that addsvnode to end of linked list
 * @head: this points to first element in linked list
 * @n: this reps the data to add new member of list
 *
 * Return: returns pointer to new node for succes else NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *k = *head;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = n;
		new->next = NULL;
	}
	else
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (k->next)
	{
		k = k->next;
	}
	k->next = new;
	return (new);
}

