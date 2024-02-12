#include "lists.h"

/*
 * free_dlistint - linked dlistint_t list freed
 * @head: head of dlistint_t
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *tm;

    while (head)
    {
        tm = head->next;
        free(head);
        head = tm;
    }
}
