#include "lists.h"

/**
 * add_dnodeint_end - new node added at end of dlistint_t list
 * @head: points to head of dlistint_t list
 *
 * Return: NULL for fail else new node addres
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
        dlistint_t *nw, *lst;

        nw = malloc(sizeof(dlistint_t));

        if (nw == NULL)
                return (NULL);

        nw->n = n;

        nw->next = NULL;

        if (*head == NULL)
        {
                nw->prev = NULL;
                *head = nw;
                return (nw);
        }

        lst = *head;
        while (lst->next != NULL)
                lst = lst->next;
        lst->next = nw;
        nw->prev = lst;

        return (nw);
}
