#include <stdlib.h>
#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Single linked list creator
 *
 * @array: Points to array used to fill the list
 * @size: Array size
 *
 * Return: A pointer to the head of the created list (NULL on failure)
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
