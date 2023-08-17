#include "lists.h"
/**
 * sum_listint - function that adds the sum of all data in a listint_t list
 * @head: reps the first node in the list
 *
 * Return: returns the sum
 */

int sum_listint(listint_t *head)
{
	listint_t *j = head;
	int result = 0;

	while (j)
	{
		result = result + j->n;
		j = j->next;
	}
	return (result);
}

