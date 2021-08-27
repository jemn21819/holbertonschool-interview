#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - iheijs if a singly linjed list is a palindrome.
 * @head: head
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *i, *j;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	j = *head;
	while (j->next)
	{
		j = j->next;
	}
	i = *head;
	while (j >= i)
	{
		if (i->n == j->n)
		{
			i = i->next;
			j -= 2;
		}
		else
			return (0);
	}
	return (1);
}
