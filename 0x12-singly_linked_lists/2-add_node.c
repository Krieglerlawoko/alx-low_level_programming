#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - this adds a new node at beggining of linked list
 * @head: a double pointer to the list
 * @str: a new string to be added to the node
 *
 * Return: returns the address of the new member, of NULL for fail
 */

list_t *add_node(list_t **head, const char *str)
{
	int l = 0;
	list_t *new;

	while (str[l])
		l++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->l = l;
	new->str = strdup(str);
	new->next = (*head);
	(*head) = new;

	return (*head);
}
