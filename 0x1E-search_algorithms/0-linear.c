#include "search_algos.h"

/**
 * linear_search - Value searched for in array of
 * ints using Linear search algorithm
 *
 * @array: Array input
 * @size: Array size
 * @value: value searched for
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int a;

	if (array == NULL)
		return (-1);

	for (a = 0; a < (int)size; a++)
	{
		printf("Value checked array[%u] = [%d]\n", a, array[a]);
		if (value == array[a])
			return (a);
	}
	return (-1);
}
