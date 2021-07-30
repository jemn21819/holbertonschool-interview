#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the head
 * @number: number to add
 * Return: The address to the new node or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *curr = NULL;
	listint_t *new = NULL;

	if (!head)
		return (NULL);
	curr = *head;
	new = malloc(sizeof(listint_t));
	new->n = number;
	new->next = NULL;

	if (!curr)
	{
		*head = new;
		return (new);
	}
	if (number < curr->n)
	{
		new->next = curr;
		*head = new;
		return (new);
	}
	while (curr->next && curr->next->n <= number)
		curr = curr->next;
	new->next = curr->next;
	curr->next = new;
	return (new);
}
