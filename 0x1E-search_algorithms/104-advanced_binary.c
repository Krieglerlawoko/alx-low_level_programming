#include "search_algos.h"

/**
 * rec_search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int rec_search(int *array, size_t size, int value)
{
	size_t a;
	size_t h = size / 2;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (a = 0; a < size; a++)
		printf("%s %d", (a == 0) ? ":" : ",", array[a]);

	printf("\n");

	if (h && size % 2 == 0)
		h--;

	if (value == array[h])
	{
		if (h > 0)
			return (rec_search(array, h + 1, value));
		return ((int)h);
	}

	if (value < array[h])
		return (rec_search(array, h + 1, value));

	h++;
	return (rec_search(array + h, size - h, value) + h);
}

/**
 * advanced_binary - rec_search called to return
 * index of the number
 *
 * @array: Array input
 * @size: Array size
 * @value: Search value
 * Return: Number index
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = rec_search(array, size, value);

	if (i >= 0 && array[i] != value)
		return (-1);

	return (i);
}
