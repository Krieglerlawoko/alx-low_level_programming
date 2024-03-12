#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

/**
 * main - Point of entry
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        1, 4, 1, 3, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 9, 9, 9, 10, 10
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, interpolation_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 7, interpolation_search(array, size, 7));
    printf("Found %d at index: %d\n", 999, interpolation_search(array, size, 999));
    return (EXIT_SUCCESS);
}
