#include "lists.h"
/**
 * print_listint - function that prints all a linked lists members
 * @h: list to be printed
 *
 * Return: returns the number of nodes of the list
 */

size_t print_listint(const listint_t *h)
{
	size_t j = 0;


	while (h)
	{
		printf("%d\n", h->n);

		j++;
		h = h->next;
	}
	return (j);
}
