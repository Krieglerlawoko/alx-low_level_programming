#include "hash_tables.h"

/**
 * key_index - Get index at which key/value
 * @key: key to get the index
 * @size: The size array of the hash table
 *
 * Return: index of key
 * Description: djb2 algorithm used
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
