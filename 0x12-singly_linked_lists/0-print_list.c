#include "lists.h"
#include <stdio.h>

/**
 * print_list - All elements of linked list printed
 * @h: Points to list_t list to print
 *
 * Return: No. of nodes printed
 */
size_t print_list(const list_t *h)
{
 size_t a = 0;

 while (h)
 {
 if (!h->str)
 printf("[0] (nil)\n");
 else
 printf("[%u] %s\n", h->len, h->str);
 h = h->next;
 a++;
 }

 return (a);
}
