#include "hash_tables.h"

/**
 * hash_table_print - hash table is printed
 * @ht: hash table pointer
 *
 * Description: Key/value pairs are printed in the order
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *n;
	unsigned long int j;
	unsigned char cflag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			if (cflag == 1)
				printf(", ");

			n = ht->array[j];
			while (n != NULL)
			{
				printf("'%s': '%s'", n->key, n->value);
				n = n->next;
				if (n != NULL)
					printf(", ");
			}
			cflag = 1;
		}
	}
	printf("}\n");
}
