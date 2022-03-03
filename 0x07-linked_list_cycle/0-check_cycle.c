#include "lists.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * check_cycle - function that check if a list has a cycle
 * @list: the list to check
 * Return: 1 if there is a cycle or 0
 */


int check_cycle(listint_t *list)
{
  listint_t *fast;
  listint_t *slow;

  if (!list)
    return (0);
  fast = list->next;
  slow = list;
  while (fast && slow && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
	return (1);
    }
  return (0);
 }
