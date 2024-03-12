#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

/**
 * print_skiplist - Content of a skiplist_t dumped
 *
 * @list: Points to head of list
 *
 * Return: void
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *n;

	printf("List :\n");
	for (n = list; n; n = n->next)
	{
		printf("Index[%lu] = [%d]\n", n->index, n->n);
	}
	printf("\nExpress lane :\n");
	for (n = list; n; n = n->express)
	{
		printf("Index[%lu] = [%d]\n", n->index, n->n);
	}
	printf("\n");
}
