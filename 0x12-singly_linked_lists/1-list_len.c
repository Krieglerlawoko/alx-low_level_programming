#include <stdlib.h>
#include "lists.h"

/**
 * list_len - this returns the no. of elements in linked list
 * @h: this is a pointer to the list
 *
 * Return: returns the no. of elements in h
 */

size_t list_len(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		k++;
		h = h->next;
	}
	return (k);
}
