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
        unsigned int a;

        if (head == NULL)
                return (NULL);

        while (head->prev != NULL)
                head = head->prev;

        a = 0;

        while (head != NULL)
        {
                if (a == index)
                        break;
                head = head->next;
                a++;
        }

        return(head);
}
