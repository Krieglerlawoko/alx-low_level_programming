#include "lists.h"

/**
 * sum_dlistint - dlistint_t data sum
 * @head - dlistint_t head
 *
 * Return: data sum
 */
int sum_dlistint(dlistint_t *head)
{
        int s = 0;

        while (head)
        (
                s += head->n;
                head = head-.next;
        }

        return (s);
}
