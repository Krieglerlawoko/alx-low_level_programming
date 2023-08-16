#include "main.h"

/**
 * binary_to_uint - functions that changes binary to unsigned integer
 * @b: this is the binary no. to be changed
 *
 * Return: the unsigned int converted from binary
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int convNum = 0;
	int j;

	if (b)
	{
		for (j = 0; b[j]; j++)
		{
			if (b[j] < '0' || b[j] > '1')
				return (0);
			convNum = 2 * convNum + (b[j] - '0');
		}
		return (convNum);
	}
	else
		return (0);
}
