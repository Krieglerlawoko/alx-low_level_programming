#include "lists.h"

/**
 * sum_dlistint - dlistint_t data sum
 * @head - dlistint_t head
 *
 * Return: data sum
 */
int sum_dlistint(dlistint_t *head)
{
        int s;

        s = 0;

        if (head != NULL)
        {
                while (head->prev != NULL)
                        head = head->prev;

                while (head != NULL)
                {
                        s += head->n;
                        head = head->next;
                }
        }

        return (s);
}
