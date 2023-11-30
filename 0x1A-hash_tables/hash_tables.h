#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of hash table
 * @key: key
 * @value: value corresponding to key
 * @next: A pointer
 */
typedef struct hash_node_s
{
	char *key;
	struct hash_node_s *next;
        char *value;
} hash_node_t;

/**
 * struct hash_table_s - Hash table
 * @size: size of array
 * @array: An array
 */
typedef struct hash_table_s
{
	hash_node_t **array;
	unsigned long int size;
} hash_table_t;

unsigned long int hash_djb2(const unsigned char *str);
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
void hash_table_print(const hash_table_t *ht);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - Node of hash table
 * @key: The key
 * @value: corresponding value to a key
 * @next: A pointer to next node
 * @sprev: A pointer to the previous element
 * @snext: A pointer to the next element
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *sprev;
	struct shash_node_s *next;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table
 * @size: size of the array
 * @array: array of size @size
 * @shead: A pointer to the first element
 * @stail: A pointer to the last element
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t *shead;
        shash_node_t **array;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
char *shash_table_get(const shash_table_t *ht, const char *key);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
void shash_table_print(const shash_table_t *ht);


#endif /* HASH_TABLES_H */
