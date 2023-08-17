#include "lists"
/**
 * free_listint - function that will free a linked list
 * @head: reps the list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *k;

	while (head)
	{
		k = head->next;
		free(head);
		head = k;
	}
}
