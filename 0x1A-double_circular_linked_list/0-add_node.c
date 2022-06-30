#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a
 * double circular linked list
 * @list:the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *current;
	List *first;
	List *new_node = NULL;
	/* if listt not exists return null */
	if (!list)
		return (NULL);
	current = *list;
	first = *list;
	/* asign memory for the new node and verify if success */
	new_node = malloc(sizeof(list));
	if (!new_node)
		return (NULL);
	/* set default data for the node */
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->str = str;
	/* if list is empty add the new node at the beggin*/
	if (*list == NULL)
	{
		*list = new_node;
		return (new_node);
	}
	else
	{
		while (current)
		{
			if (!current->next || current->next == *list)
			{
				new_node->prev = current;
				current->next = new_node;
				/* make it circular:*/
				new_node->next = *list;
				first->prev = new_node;
				return (new_node);
			}
			current = current->next;
		}
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a
 * double circular linked list
 * @list:the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *current;
	List *first;
	List *new_node = NULL;
	/* if listt not exists return null*/
	if (!list)
		return (NULL);
	current = *list;
	first = *list;
	/* asign memory for the new node and verify if success*/
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	/* set default data for the node*/
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->str = str;
	/* if list is empty add the new node at the beggin*/
	if (*list == NULL)
	{
		*list = new_node;
		return (new_node);
	}
	else
	{
		new_node->next = current;
		current->prev = new_node;
		*list = new_node;

		while (current)
		{
			if (!current->next || current->next == first)
			{
				new_node->prev = current;
				current->next = new_node;
				return (new_node);
			}
			current = current->next;
		}
	}
	return (new_node);
}
