#include "search_algos.h"

/**
  * _binary_search - Value searched in a sorted array
  *                  of ints using binary search.
  * @array: Points to first element of array to search.
  * @left: Starting index of sub-array to search.
  * @right: Ending index of sub-array to search.
  * @value: Search value.
  *
  * Return: If value is not present or the array is NULL, -1.
  *         else, index where value is located.
  *
  * Description: Sub-array being searched after each change printed.
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (a = left; a < right; a++)
			printf("%d, ", array[a]);
		printf("%d\n", array[a]);

		a = left + (right - left) / 2;
		if (array[a] == value)
			return (a);
		if (array[a] > value)
			right = a - 1;
		else
			left = a + 1;
	}

	return (-1);
}

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: PointS to first element of array to search.
  * @size: Number of elements in array.
  * @value: Search value.
  *
  * Return: If the array is NULL or value is not present, -1.
  *         else, index where value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t r, a = 0;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (a = 1; a < size && array[a] <= value; a = a * 2)
			printf("Value checked array[%ld] = [%d]\n", a array[a]);
	}

	r = a < size ? a : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", a / 2, r);
	return (_binary_search(array, a / 2, r, value));
}
