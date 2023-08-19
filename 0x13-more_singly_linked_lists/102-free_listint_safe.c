#include "lists.h"

/**
 * free_listint_safe -function that frees linked lists
 * @h: points to first node in the list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	int dfrenc;
	size_t lngh = 0;
	listint_t *j;

	if (h || *h)
	{
		while (*h)
		{

			dfrenc = *h - (*h)->next;

			if (dfrenc < 0)
			{

				free(*h);
				*h = NULL;
				lngh++;
				break;
			}
			else
			{
				j = (*h)->next;
				free(*h);
				*h = j;
				lngh++;
			}

		}
	}
	else
		return (0);

	*h = NULL;

	return (lngh);
}

