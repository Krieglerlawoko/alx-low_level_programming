#include "main.h"

/**
 * clear_bit - function that sets value of bit to 0
 * @n: reps a pointer to no. to work on
 * @index: reps the index of bit to be cleared
 *
 * Return: on success 1 and -1 on fail
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (!(index < 63))
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
