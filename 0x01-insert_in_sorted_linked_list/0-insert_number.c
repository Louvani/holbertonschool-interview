#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - insert elements on a listint_t list
 * @head: pointer to head of list
 * @number: value
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number) {
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
        {
            if (current->n < number && current->next->n > number)
            {
                new->next = current->next;
                current->next = new;
                return (new);
            }
            else
                current = current->next;
        }
        current->next = new;
    }
    return (new);
}