#include "Lists.h"

/**
 * add_dnodeint - new node at beginnnig of dlistint_t
 * @head: points to dlistint_t list
 * @n: int for  new node to carry
 *
 * Return: if fails NULL else address of new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{

        dlistint_t *nw;

        nw = malloc(sizeof(dlistint_t));

        if (nw == NULL)
                return (NULL);

        nw->n = n;
        nw->prev = NULL;
        nw->next = *head;
        if (*head != NULL)

                (*head)->prev = nw;
        *head = nw;

        return (nw);
}
