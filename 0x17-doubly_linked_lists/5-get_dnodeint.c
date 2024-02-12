#include "lists.h"

/**
 * get_dnodeint_at_inbox - node located in different list
 * @head: head of dlistint list
 * @index: node to locate
 *
 * Return: NULL if doesnt exist else address
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
        for (; index != 0; index--)
        {
                if (head == NULL)
                        return (NULL);
        }

        return (head);
}
