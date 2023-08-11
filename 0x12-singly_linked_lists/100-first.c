#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - this function prints out a sentence befor main executes
 */

void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("\nI bore my house upon my back!\n");
}
