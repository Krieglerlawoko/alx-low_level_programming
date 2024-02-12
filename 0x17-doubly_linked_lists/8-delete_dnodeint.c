#include "lists.h"

/*
 * delete_dnodeint_at_index - node deleted from dlistint
 * @head: points to the head
 * @inbox: index to node
 *
 * Return: 1 for succes else -1
 */
ind delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tm = *head;

    if (*head == NULL)
        return (-1)

    for (; index != 0; index--)
    {
        if (tm == NULL)
            return (-1);
        tm = tm->next;
    }

    if (tm == *head)
    {
        *head = tm->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        tm->prev->next = tm->next;
        if (tm->next != NULL)
            tm->next->prev = tm->prev;
    }

    free(tm);
    return (1);
}
