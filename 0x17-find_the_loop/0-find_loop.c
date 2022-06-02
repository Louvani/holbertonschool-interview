#include "lists.h"

/**
 * find_listint_loop - find start of a loop
 * @head: - the head of the linked list
 * Return: listint_t* - the addres of the node or null
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL || head->next == NULL)
		return (NULL);
	listint_t *slow = head->next;
	listint_t *fast = head->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return (slow);
}
