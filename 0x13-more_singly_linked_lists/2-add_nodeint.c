#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

#include "lists.h"
/**
 * add_nodeint - function that adds new node to beginning of link list
 * @head: this is a pointer to first node
 * @n: reps data to be inserted at beginning of linked list
 *
 * Return: returns pointer to a new added node else Null for fail
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = n;
		new->next = *head;
		*head = new;

		return (new);
	}
	else
	{
		return (NULL);
	}
}

