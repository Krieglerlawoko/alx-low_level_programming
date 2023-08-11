#include <stdlib.h>
#include "lists.h"

/**
 * free_list - function that frees linked lists
 * @head: pointer to the lists to free
 */

void free_list(list_t *head)
{
	list_t *m;

	while (head)
	{
		m = head->next;
		free(head->str);
		free(head);
		head = m;
	}
}
