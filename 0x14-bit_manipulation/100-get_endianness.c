#include "main.h"

/**
 * get_endianness - this function checks endiannesse of a machine
 *
 * Return: 1 for small endian and 0 for big endian
 */

int get_endianness(void)
{
	int k = 1;
	char *j = (char *) &k;

	return (*j);
}
