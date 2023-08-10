#include <stdio.h>
#include "list.h"

/**
 * print_list - this prints all the elements of a linked list
 * @h: this is a pointer to the list to print
 *
 * Return: returns the no. of nodes to be printed
 */

size_t print_list(const list_t *h)
{
	size_t k = 0;
	
	while (h)
	{
		if (!h->str)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next;
		k++;
	}
	return (k);
}

