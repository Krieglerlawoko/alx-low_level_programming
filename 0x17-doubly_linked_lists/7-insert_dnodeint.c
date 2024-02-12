#include "lists.h"

/*
 * insert_dnodeint_at_index - new node insert to dlistnit
 * @h: points to head
 * @idx: position for insert
 * @n: int for new nod to carry
 *
 * Return NULL for fail else address
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *hd, *nw;
    unsigned int a;


    nw = NULL;
    if (idx == 0)
            nw = add_dnodeint(h, n);
    else
    {
            hd = *h;
            a = 1;
            if (hd != NULL)
                    while (hd->prev != NULL)
                            hd = hd->prev;
            while (hd != NULL)
            {
                    if (a == idx)
                    {
                            if (hd->next == NULL)
                                    nw = add_dnodeint_end(h, n);
                            else
                            {
                                    nw = malloc(sizeof(dlistint_t));
                                    if (nw != NULL)
                                    {
                                            nw->n = n;
                                            nw->next = hd->next;
                                            nw->prev = hd;
                                            hd->next->prev = nw;
                                            hd->next = nw;
                                    }
                            }
                            break;
                    }
                    hd = hd->next;
                    a++;
            }
     }

     return (nw);
}
