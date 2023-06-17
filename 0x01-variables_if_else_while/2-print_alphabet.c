#include <stdlib.h>
#include <time.h>

/**
 * main - signs a random number to n
 * @void - takes no argument
 *
 * Description: this function prints out the last digit of a number
 * Return: Always 0
 */

int main(void)
{
	char alp[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; i < 26; i++)
	{
		putchar(alp[i]);
	}
	putchar('\n');
	return (0);
}
