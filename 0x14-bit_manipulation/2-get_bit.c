#include "main.h"
/**
 * get_bit - function that returns value of bit at index of a decimal
 * @n: the number to search for value from
 * @index: this is the index of the bit
 *
 * Return: function returns the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int j;

	if (!(index < 63))
		return (-1);
	j = (n >> index) & 1;

	return (j);
}
