#include "search_algos.h"

/**
  * binary_search - Value serched in sorted array
  *                 of ints using binary search.
  * @array: Points to the first element of the array to search.
  * @size: No. of elements in array.
  * @value: Value searched for
  *
  * Return: If NULL or value is not present, -1.
  *         else, index where value is located.
  *
  * Description: sub-array being searched after each change printed.
  */
int binary_search(int *array, size_t size, int value)
{
	size_t a, l, right;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		printf("Searching in array: ");
		for (a = l; a < r; a++)
			printf("%d, ", array[a]);
		printf("%d\n", array[a]);

		a = l + (r - l) / 2;
		if (array[a] == value)
			return (a);
		if (array[a] > value)
			r = a - 1;
		else
			l = a + 1;
	}

	return (-1);
}

