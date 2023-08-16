#include "main.h"
#include <unistd.h>

/**
 * _putchar - function that writes c character too standard output
 * @c: the char c that is pirnted
 *
 * Return: if succesful returns 1 else -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
