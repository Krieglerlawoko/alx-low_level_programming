#include "main.h"
/**
 * flip_bits - function counts the no. of bits to be altered
 * @n: number one
 * @m: number two
 *
 * Return: returns the no. of bits to be altered
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int j;
	int numTim = 0;
	int k;
	unsigned long int l = n ^ m;

	for (k = 63; k >= 0; k--)
	{
		j = l >> k;

		if (j & 1)
			numTim++;
	}
	return (numTim);
}
