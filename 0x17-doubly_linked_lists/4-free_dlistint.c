#include "lists.h"

/*
 * free_dlistint - linked dlistint_t list freed
 * @head: head of dlistint_t
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *tm;

    if (head != NULL)
            while (head->prev != NULL)
                    head = head->prev;

    while ((tm = head) != NULL)
    {
            head = head->next;
            free(tm);
    }
}
