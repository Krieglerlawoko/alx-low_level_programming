#include "lists.h"
#include <string.h>

/**
 * add_node_end - this adds new nod to end of linked list
 * @head: is a double pointer to the list
 * @str: is a string to put in the new node
 *
 * Return: returns the address of the new element and NULL for fail
 */

list_t *add_node_end(list_t **head, const char *str)
{
	int l = 0;
	list_t *new;
	list_t *em = *head;

	while (str[l])
		l++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->l = l;
	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (em->next)
		em = em->next;

	em->next = new;

	return (new);
}
