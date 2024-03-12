#include <stdio.h>
#include <stdlib.h>
#include "../search_algos.h"

void print_list(const listint_t *list);
listint_t *create_list(int *array, size_t size);
void free_list(listint_t *list);

/**
 * main - Point of entry
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    listint_t *l, *r;
    int array[] = {
        0, 2, 3, 4, 5, 8, 13, 16, 19, 20, 24, 54, 62, 63, 77, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    l = create_list(array, size);
    print_list(l);

    r =  jump_list(l, size, 53);
    printf("Found %d at index: %lu\n\n", 53, r->index);
    r =  jump_list(l, size, 2);
    printf("Found %d at index: %lu\n\n", 2, r->index);
    r =  jump_list(l, size, 999);
    printf("Found %d at index: %p\n", 999, (void *) r);

    free_list(list);
    return (EXIT_SUCCESS);
}
