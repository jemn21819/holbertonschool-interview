#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: The address of the loop node, NULL otherwise
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *x = head;
	listint_t *y = head;

	if (!head)
		return (NULL);

	while (y && y->next)
	{
		x = x->next;
		y = y->next->next;
		if (x == y)
		{
			x = head;
			while (x != y)
			{
				x = x->next;
				y = y->next;
			}
			return (y);
		}
	}
	return (NULL);
}
