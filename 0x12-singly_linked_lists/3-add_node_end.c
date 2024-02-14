#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
* _strlen - length of a string
* @str: strn to find length of
*
* Return: len of strn
*/
unsigned int _strlen(char *str)
{
   unsigned int a;


   for (a = 0; str[a]; a++)
       ;
   return (a);
}


/**
* add_node_end - New node added to end of linked list
* @head: double pointer to linked list
* @str: strn to add to new node
*
* Return: points to new node
*/
list_t *add_node_end(list_t **head, const char *str)
{
   list_t *n, *temp;


   if (str == NULL)
       return (NULL);
   n = malloc(sizeof(list_t));
   if (n == NULL)
       return (NULL);
   n->str = strdup(str);
   if (n->str == NULL)
   {
       free(n);
       return (NULL);
   }
   n->len = _strlen(n->str);
   n->next = NULL;
   if (*head == NULL)
   {
       *head = n;
       return (n);
   }
   temp = *head;
   while (temp->next)
       temp = temp->next;
   temp->next = n;
   return (n);
}
