#include "main.h"
/**
 * _memset - fill block of memory with a value
 * @s: start address of memory to filled
 * @b: the desired value
 * @n: no. of bytes to changed
 *
 * Return: array with new value for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
