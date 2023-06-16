#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the alphabet
 * @void - not return value
 *
 * Description: main prints the alphabet in lower case
 * Return: 0 always
 */

int main(void)
{
	char lower = 'a';

	while (lower <= 'z')
	{
		if (lower == 'e' || lower == 'q')
		{
			++lower;
		}
		putchar(lower);
		++lower;
	}
	putchar('\n');

	return (0);
}
