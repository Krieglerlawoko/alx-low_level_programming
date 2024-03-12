#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

void print_skiplist(const skiplist_t *list);
skiplist_t *create_skiplist(int *array, size_t size);
void free_skiplist(skiplist_t *list);

/**
 * main - Point of entry
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *l, *r;
    int array[] = {
        0, 2, 3, 4, 5, 8, 13, 16, 19, 20, 24, 54, 62, 63, 77, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    l = create_skiplist(array, size);
    print_skiplist(l);

    r =  linear_skip(l, 53);
    printf("Found %d at index: %lu\n\n", 53, r->index);
    r =  linear_skip(l, 2);
    printf("Found %d at index: %lu\n\n", 2, r->index);
    r =  linear_skip(l, 999);
    printf("Found %d at index: %p\n", 999, (void *) r);

    free_skiplist(l);
    return (EXIT_SUCCESS);
}
