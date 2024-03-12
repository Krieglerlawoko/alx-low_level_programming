#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        1, 2, 3, 4, 5, 8, 13, 16, 19, 20, 24, 55, 62, 63, 77, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));
    return (EXIT_SUCCESS);
}
