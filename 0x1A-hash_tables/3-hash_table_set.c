#include "hash_tables.h"

/**
 * hash_table_set - Add or update element in hash table
 * @ht: A pointer to hash table
 * @key: The key to add - cannot be empty string
 * @value: value associated with key
 *
 * Return: Upon failure 0 or -1
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
        char *val_copy;
	hash_node_t *new;
	unsigned long int index, j;

	if (key == NULL || ht == NULL || *key == '\0' || value == NULL)
		return (0);

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (j = index; ht->array[j]; j++)
	{
		if (strcmp(ht->array[j]->key, key) == 0)
		{
			free(ht->array[j]->value);
			ht->array[j]->value = val_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(val_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = val_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
