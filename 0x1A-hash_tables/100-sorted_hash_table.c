#include "hash_tables.h"

void shash_table_delete(shash_table_t *ht);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/**
 * shash_table_create - sorted hash table creator
 * @size: size of new hash table
 *
 * Return: If an error occurs NULL else pointer
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int a;
	shash_table_t *hast;

	hast = malloc(sizeof(shash_table_t));
	if (hast == NULL)
		return (NULL);

	hast->size = size;
	hast->array = malloc(sizeof(shash_node_t *) * size);
	if (hast->array == NULL)
		return (NULL);
	for (a = 0; a < size; a++)
		hast->array[a] = NULL;
	hast->shead = NULL;
	hast->stail = NULL;

	return (hast);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: failure 0 else 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *n, *tm;
	char *val_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tm = ht->shead;
	while (tm)
	{
		if (strcmp(tm->key, key) == 0)
		{
			free(tm->value);
			tm->value = val_copy;
			return (1);
		}
		tm = tm->snext;
	}

	n = malloc(sizeof(shash_node_t));
	if (n == NULL)
	{
		free(val_copy);
		return (0);
	}
	n->key = strdup(key);
	if (n->key == NULL)
	{
		free(val_copy);
		free(n);
		return (0);
	}
	n->value = val_copy;
	n->next = ht->array[index];
	ht->array[index] = n;

	if (ht->shead == NULL)
	{
		n->sprev = NULL;
		n->snext = NULL;
		ht->shead = n;
		ht->stail = n;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		n->sprev = NULL;
		n->snext = ht->shead;
		ht->shead->sprev = n;
		ht->shead = n;
	}
	else
	{
		tm = ht->shead;
		while (tm->snext != NULL && strcmp(tm->snext->key, key) < 0)
			tm = tm->snext;
		n->sprev = tm;
		n->snext = tm->snext;
		if (tm->snext == NULL)
			ht->stail = n;
		else
			tm->snext->sprev = n;
		tm->snext = n;
	}

	return (1);
}

/**
 * shash_table_get - get value associated with
 *                   a key
 * @ht: A pointer to hash table.
 * @key: The key to value got
 *
 * Return: If no match NULL
 *         else value associated with key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int ind;
	shash_node_t *n;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	ind = key_index((const unsigned char *)key, ht->size);
	if (ind >= ht->size)
		return (NULL);

	n = ht->shead;
	while (n != NULL && strcmp(n->key, key) != 0)
		n = n->snext;

	return ((n == NULL) ? NULL : n->value);
}

/**
 * shash_table_print - sorted hash table printer
 * @ht: A pointer to sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *n;

	if (ht == NULL)
		return;

	n = ht->shead;
	printf("{");
	while (n != NULL)
	{
		printf("'%s': '%s'", n->key, n->value);
		n = n->snext;
		if (n != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints revesed sorted hash table
 * @ht: A pointer to sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *n;

	if (ht == NULL)
		return;

	n = ht->stail;
	printf("{");
	while (n != NULL)
	{
		printf("'%s': '%s'", n->key, n->value);
		n = n->sprev;
		if (n != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete- sorted hashtable deletor
 * @ht: A pointer to sorted hashtable
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *hed = ht;
	shash_node_t *n, *tm;

	if (ht == NULL)
		return;

	n = ht->shead;
	while (n)
	{
		tm = n->snext;
		free(n->key);
		free(n->value);
		free(n);
		n = tm;
	}

	free(hed->array);
	free(hed);
}
