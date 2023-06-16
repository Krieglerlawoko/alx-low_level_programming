#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints lowcase alphabetical letters and a new line
 * @void: no return value
 *
 * Description: prints lowcase alphabet and a new line
 * Return: 0 always
 */

int main(void)
{
	char lower = 'a';
	char upper = 'A';

	while (lower <= 'z')
	{
		putchar(lower);
		++lower;
	}

	while (upper <= 'z')
	{
		putchar(upper);
		++upper;
	}
	putchar('\n');

	return (0);
}
