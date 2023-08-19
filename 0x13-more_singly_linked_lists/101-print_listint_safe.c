#include "lists.h"
#include <stdio.h>

size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

/**
 * looped_listint_len -fonction counts number of unique nodes
 * @head: points to listint head to work on
 *
 * Return: returns 0 if list has no loop else no
 * of unique nodes in the list.
 */


size_t looped_listint_len(const listint_t *head)
{
	size_t j = 1;
	const listint_t *k;        
	const listint_t *l;
    
        if (!(head == NULL) || !(head->next == NULL))
        {
	l = head->next;
	k = (head->next)->next;
        }
        else
        {
		return (0);
        }




	while (k)
	{
		if (l == k)
		{
			l = head;
			while (l != k)
			{
				j++;
				l = l->next;
				k = k->next;
			}

			l = l->next;
			while (l != k)
			{
				j++;
				l = l->next;
			}

			return (j);
		}

		l = l->next;
		k = (k->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - function that prints a listint_t list.
 * @head: points to head of the list.
 *
 * Return: returns no. of nodes in list.
 */


size_t print_listint_safe(const listint_t *head)
{
	size_t j;
	size_t num = 0;

	j = looped_listint_len(head);

        if (!(j == 0))
	{
		for (num = 0; num < j; num++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	else
	{
		for (; head != NULL; j++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	return (j);
}

