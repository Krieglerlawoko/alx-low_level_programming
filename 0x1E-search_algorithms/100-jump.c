#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Value searched in array of
 * ints using Jump search algorithm
 *
 * @array: Array input
 * @size: Array size
 * @value: value searched in
 * Return: number index
 */
int jump_search(int *array, size_t size, int value)
{
	int i, a, b, p;

	if (size == 0 || array == NULL)
		return (-1);

	a = (int)sqrt((double)size);
	b = 0;
	p = i = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
		b++;
		p = i;
		i = b * a;
	} while (i < (int)size && array[i] < value);

	printf("Value found between indexes [%d] and [%d]\n", p, i);

	for (; p <= i && p < (int)size; p++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[p]);
		if (array[p] == value)
			return (p);
	}

	return (-1);
}
