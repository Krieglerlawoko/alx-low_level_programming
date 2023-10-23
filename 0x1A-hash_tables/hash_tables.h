#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of hash table
 * @key: The key
 * @value: The value corresponding to key
 * @next: pointer to next node of List
 */
typedef struct hash_node_s
{
	char *key;
        struct hash_node_s *next;
	char *value;
} hash_node_t;

/**
 * struct hash_table_s - Hash table
 * @size: The size array
 * @array: array of size @size
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);

/**
 * struct shash_node_s - Node of hash table
 * @key: key
 * @value: The corresponding value to a key
 * @next: pointer to next node of the List
 * @sprev: pointer to previous element of the sorted linked list
 * @snext: pointer next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *value;
        char *key;
	struct shash_node_s *next;
        struct shash_node_s *snext;
	struct shash_node_s *sprev;
} shash_node_t;

/**
 * struct shash_table_s - hash table sorted data structure
 * @size: size of the array
 * @array: array of size @size
 * @shead: pointer to the first element the sorted
 * @stail: pointer to the last element
 */
typedef struct shash_table_s
{
	unsigned long int size;
        shash_node_t *stail;
        shash_node_t *shead;
	shash_node_t **array;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);

#endif /* HASH_TABLES_H */
