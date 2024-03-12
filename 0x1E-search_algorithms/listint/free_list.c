#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_list - Singly linked list deallocated
 *
 * @list: PointS to linked list to freed
 */
void free_list(listint_t *list)
{
	listint_t *n;

	if (list)
	{
		n = list->next;
		free(list);
		free_list(n;
	}
}
