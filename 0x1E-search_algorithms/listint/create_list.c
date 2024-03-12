#include <stdlib.h>
#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Single linked list created
 *
 * @array: Points to array to use to fill list
 * @size: Array size
 *
 * Return: Points to head of created list 
 * else NULL for failure
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *n;
	listint_t *l;

	l = NULL;
	while (array && size--)
	{
		n = malloc(sizeof(*n));
		if (!n)
		{
			free_list(l);
			return (NULL);
		}
		n->n = array[size];
		n->index = size;
		n->next = list;
		l = n;
	}
	return (l);
}
