#include "search_algos.h"

/**
  * binary_search_recursive - Searches recursively for a value in a sorted
  *                           array of integers using binary search.
  * @array: Points to 1st element of sub-array to search.
  * @left: Starting index of sub-array to search.
  * @right: The ending index of sub=array to search.
  * @value: The value to search for.
  *
  * Return: If value is not present, -1.
  *         else, index where value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (a = left; a < right; a++)
		printf("%d, ", array[a]);
	printf("%d\n", array[a]);

	a = left + (right - left) / 2;
	if (array[a] == value)
		return (a);
	if (array[a] > value)
		return (binary_search_recursive(array, left, a - 1, value));
	return (binary_search_recursive(array, a + 1, right, value));
}

/**
  * binary_search - Searches for value in sorted int
  *                 array using binary search.
  * @array: Points to 1st element of array searched.
  * @size: Number of array elements.
  * @value: Value searched.
  *
  * Return: If the array is NULL or value is not present, -1.
  *         else, index where value is located.
  *
  * Description: sub-array being searched printed after each change.
  */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
