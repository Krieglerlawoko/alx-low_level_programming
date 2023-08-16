#include "main.h"
/**
 * print_binary - function prints binary equal of a decimal no.
 * @n: this is the binary no. printed
 */

void print_binary(unsigned long int n)
{
	unsigned long int curntNum;
	int j;
	int numTim = 0;

	for (j = 63; j >= 0; j--)
	{
		curntNum = n >> j;
		if (curntNum & 1)
		{
			_putchar('1');
			numTim++;
		}
		else if (numTim)
		{
			_putchar('0');
		}
	}
	if (!numTim)
		_putchar('0');
}


