#include "lists.h"

/**
 * print_dlistint - all elements of dlistint_t list
 * @h: head of dlistint_t list
 *
 * Return: no. of nodes in list
 */
size_t print_dlistint(const dlistint_t *h)
{
        size_t nods = 0;

        while (h)
        {
                nods++;

                printf("%d\n", h->n);

                h = h->next;
        }

        return (nods);
}
