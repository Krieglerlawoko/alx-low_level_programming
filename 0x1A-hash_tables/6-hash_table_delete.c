#include "hash_tables.h"

/**
 * hash_table_delete - hash table deleter
 * @ht: pointer to hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hed = ht;
	hash_node_t *n, *tm;
	unsigned long int a;

	for (a = 0; a < ht->size; a++)
	{
		if (ht->array[a] != NULL)
		{
			n = ht->array[a];
			while (n != NULL)
			{
				tm = n->next;
				free(n->key);
				free(n->value);
				free(n);
				n = tm;
			}
		}
	}
	free(hed->array);
	free(hed);
}
