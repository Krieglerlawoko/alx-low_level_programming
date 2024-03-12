#include "search_algos.h"

/**
 * interpolation_search - Value in an array of
 * ints searched using Interpolation search algorithm
 *
 * @array: Array input
 * @size: Array size
 * @value: Search value
 * Return: Number index
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t p, high l;
	double f;

	if (array == NULL)
		return (-1);

	l = 0;
	h = size - 1;

	while (size)
	{
		f = (double)(h - l) / (array[h] - array[l]) * (value - array[l]);
		p = (size_t)(l + f);
		printf("Value checked array[%d]", (int)p);

		if (p >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[p]);
		}

		if (array[p] == value)
			return ((int)p);

		if (array[p] < value)
			l = p + 1;
		else
			h = p - 1;

		if (l == h)
			break;
	}

	return (-1);
}
