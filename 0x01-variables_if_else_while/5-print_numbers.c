#include <stdio.h>
#include <stlib.h>

/**
 * main - prints base 10 digits and a single line
 *
 * Description: prints a base 10 digit and a single line
 * Return: 0 always
 */

int main(void)
{
	int n = 0;

	while (n <= 9)
	{
		printf("%d", n);
		++n;
	}
	printf("\n");
	return (0);
}
