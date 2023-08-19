#include "lists.h"

/**
 * find_listint_loop - function that a loop in linked lists
 * @head: reps linked list to work on
 *
 * Return: returns address node where loop starts for success
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *j = head;
	listint_t *k = head;

	if (head)
	{
		while (k && j && j->next)
		{

			j = j->next->next;
			k = k->next;

			if (j == k)
			{

				k = head;

				while (k != j)
				{

					k = k->next;
					j = j->next;

				}
				return (j);
			}
			else
			{
				return (NULL);
			}
		}
	}
	return (NULL);
}
