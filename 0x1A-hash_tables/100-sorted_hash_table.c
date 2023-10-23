#include "hash_tables.h"

void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
/**
 * shash_table_create - Creates hash table
 * @size: size of table
 *
 * Return: If error NULL else pointer
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hast;
	unsigned long int j;

	hast = malloc(sizeof(shash_table_t));
	if (hast == NULL)
		return (NULL);

	hast->size = size;
	hast->array = malloc(sizeof(shash_node_t *) * size);
	if (hast->array == NULL)
		return (NULL);
	for (j = 0; j < size; j++)
		hast->array[j] = NULL;
	hast->shead = NULL;
	hast->stail = NULL;

	return (hast);
}

/**
 * shash_table_set - Adds an element
 * @ht: A pointer to hash table
 * @key: The key to add
 * @value: value associated with key.
 *
 * Return: 0 for failure or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *n, *t;
	char *vcopy;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	vcopy = strdup(value);
	if (vcopy == NULL)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	t = ht->shead;
	while (t)
	{
		if (strcmp(t->key, key) == 0)
		{
			free(t->value);
			t->value = vcopy;
			return (1);
		}
		t = t->snext;
	}

	n = malloc(sizeof(shash_node_t));
	if (n == NULL)
	{
		free(vcopy);
		return (0);
	}
	n->key = strdup(key);
	if (n->key == NULL)
	{
		free(vcopy);
		free(n);
		return (0);
	}
	n->value = vcopy;
	n->next = ht->array[i];
	ht->array[i] = n;

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
		t = ht->shead;
		while (t->snext != NULL && strcmp(t->snext->key, key) < 0)
			t = t->snext;
		n->sprev = t;
		n->snext = t->snext;
		if (t->snext == NULL)
			ht->stail = n;
		else
			t->snext->sprev = n;
		t->snext = n;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve a value
 * @ht: pointer
 * @key: The key
 *
 * Return: NULL for no match else value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *n;
	unsigned long int j;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	j = key_index((const unsigned char *)key, ht->size);
	if (j >= ht->size)
		return (NULL);

	n = ht->shead;
	while (n != NULL && strcmp(n->key, key) != 0)
		n = n->snext;

	return ((n == NULL) ? NULL : n->value);
}

/**
 * shash_table_print - sorted hash table printed
 * @ht: A pointer
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
 * shash_table_print_rev - hash table in reverse order printed
 * @ht: A pointer
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
 * shash_table_delete - Deletes hash table
 * @ht: A pointer hash table to sort
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *n, *t;

	if (ht == NULL)
		return;

	n = ht->shead;
	while (n)
	{
		t = n->snext;
		free(n->key);
		free(n->value);
		free(n);
		n = t;
	}

	free(head->array);
	free(head);
}
