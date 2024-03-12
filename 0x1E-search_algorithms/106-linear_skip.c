#include "search_algos.h"

/**
 * linear_skip - Value searched in skip list
 *
 * @list: list input
 * @value: Search value
 * Return: Number index
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *a;

	if (list == NULL)
		return (NULL);

	a = list;

	do {
		list = a;
		a = a->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)a->index, a->n);
	} while (a->express && a->n < value);

	if (a->express == NULL)
	{
		list = a;
		while (a->next)
			a = a->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)a->index);

	while (list != a->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
