#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - this adds new nod to end of linked list
 * @head: is a double pointer to the list
 * @str: is a string to put in the new node
 *
 * Return: returns the address of the new element and NULL for fail
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list *temp = *head;
	unsigned int len = 0;
	list_t *new;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	
	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->l = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp>next;
	temp->next = new;

	temp->next = new;

	return (new);
}
