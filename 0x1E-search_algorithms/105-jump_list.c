#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Value searched in an array of
 * integers using the Jump search algorithm
 *
 * @list: list input
 * @size: Array size
 * @value: search value
 * Return: Number index
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t a, b, m;
	listint_t *prev;

	if (size == 0 || list == NULL)
		return (NULL);

	m = (size_t)sqrt((double)size);
	b = 0;
	a = 0;

	do {
		prev = list;
		a++;
		b = a * m;

		while (list->next && list->b < b)
			list = list->next;

		if (list->next == NULL && b != list->b)
			b = list->b;

		printf("Value checked at index [%d] = [%d]\n", (int)b, list->n);

	} while (b < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->b, (int)list->b);

	for (; prev && prev->b <= list->b; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
