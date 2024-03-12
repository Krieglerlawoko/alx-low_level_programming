#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_skiplist - Singly linked list dealocated
 *
 * @list: Points to linked list to free
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *n;

	if (list)
	{
		n = list->next;
		free(list);
		free_skiplist(n);
	}
}
