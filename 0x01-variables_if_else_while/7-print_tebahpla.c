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
	char ch;

	for (ch = 'z'; ch >= 'a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
