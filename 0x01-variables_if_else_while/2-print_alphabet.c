#include <stdlib.h>
#include <time.h>

/**
 * main - signs a random number to n
 * @void - no return value
 *
 * Description: this function prints out the last digit of a number
 * Return: Always 0
 */

int main(void)
{
	int n;
	int digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	digit = n % 10;
}
