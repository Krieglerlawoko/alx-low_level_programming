#include "lists.h"

/**
  * dlistint_len - no. of elements counts
  * @h: head of the dlistint_t list
  *
  * Return: no. elements in dlistint_t list
  */
size_t dlistint_len(count dlistint_t *h)
{
        size_t nods = 0;

        while (h)
        {

               nods++;



               h = h->next;
        }

        return (nods);
}
