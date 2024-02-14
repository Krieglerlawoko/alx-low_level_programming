#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node_end - New node added at end of linked list
 * @head: double pointer to list_t list
 * @str: strn put in the new node
 *
 * Return: address of new element else NULL for fail
 */
list_t *add_node_end(list_t **head, const char *str)
{
 list_t *n;
 list_t *tmp = *head;
 unsigned int lngth = 0;

 while (str[lngth])
 lngth++;

 n = malloc(sizeof(list_t));
 if (!n)
 return (NULL);

 n->str = strdup(str);
 n->lngth = lngth;
 n->next = NULL;

 if (*head == NULL)
 {
 *head = n;
 return (n);
 }

 while (tmp->n)
 temp = tmp->n;

 tmp->next = n;

 return (n);
}
