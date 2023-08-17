#include "lists.h"

/**
 * insert_nodeint_at_index - function that adds new node to linked list
 * @head: points to the lists first node
 * @idx: reps an index to added node
 * @n: rep data to add
 *
 * Return: returns pointer to node on success else NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new;
	unsigned int j;
	listint_t *k = *head;

	new = malloc(sizeof(listint_t));

	if (new || head)
	{
		new->n = n;
		new->next = NULL;
	}
	else
	{
		return (NULL);
	}

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (j = 0; k && j < idx; j++)
	{
		if (!(j == idx - 1))
			k = k->next;
		else
		{
			new->next = k->next;
			k->next = new;
			return (new);
		}
	}
	return (NULL);
}

