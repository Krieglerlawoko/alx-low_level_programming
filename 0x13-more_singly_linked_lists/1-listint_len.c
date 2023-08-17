#include "lists.h"
/**
 * listint_len - function that returns no. of linked lists members
 * @h: reps the list of type listint_t to work on
 *
 * Return: returns the no. of nodes the list has
 */

size_t listint_len(const listint_t *h)
{
	size_t j = 0;

	while (h)
	{
		j++;
		h = h->next;
	}
	return (j);
}
