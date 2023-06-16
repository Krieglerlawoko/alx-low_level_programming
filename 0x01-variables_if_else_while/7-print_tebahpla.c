#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints reverse alphabet
 * @void: shows main doesn't take an argument
 *
 * Description: prints the alphabet from z-a
 * Return: Always 0
 */

int main(void)
{
	char lower = 'z';

	while (lower >= 'a')
	{
		putchar(lower);
		--lower;
	}
	putchar('\n');
	return (0);
}
