#include "hash_tables.h"

/**
 * hash_table_delete - Deletes hash tables
 * @ht: pointer hash table
 */
void hash_table_delete(hash_table_t *ht)
{
        hash_node_t *n, *t;
	hash_table_t *head = ht;
	unsigned long int j;

	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			n = ht->array[j];
			while (n != NULL)
			{
				t = n->next;
				free(n->key);
				free(n->value);
				free(n);
				n = t;
			}
		}
	}
	free(head->array);
	free(head);
}
