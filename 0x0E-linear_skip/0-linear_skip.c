#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * linear_skip - Linear search in a skip list
 *
 * @list: Pointer to the head node of the list
 * @value: value to check
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *save = list;
	skiplist_t *tmp;
	char *checker = "Value checked at index [%lu] = [%d]\n";
	char *found = "Value found between indexes [%lu] and [%lu]\n";

	if (list == NULL)
	{
		return (NULL);
	}
	while (save->express != NULL)
	{
		if (save->express->n == value)
		{
			printf(checker, save->express->index, save->express->n);
			printf(found, save->index, save->express->index);
			while (save->next != NULL)
			{
				if (save->n == value)
				{
					printf(checker, save->index, save->n);
					return (save);
				}
				printf(checker, save->index, save->n);
				save = save->next;
			}
			//return (save);
		}
		if (value < save->express->n)
		{
			printf(checker, save->express->index, save->express->n);
			printf(found, save->index, save->express->index);
			for (; save->next != NULL; save = save->next)
			{
				printf(checker, save->index, save->n);
				if (save->n == value)
					return (save);
			}
		}
		save = save->express;
		printf(checker, save->index, save->n);
	}
	tmp = save;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	printf(found, save->index, tmp->index);
	while (save->next != NULL)
	{
		if (save->n == value)
		{
			printf(checker, save->index, save->n);
			return (save);
		}
		printf(checker, save->index, save->n);
		save = save->next;
	}
	printf(checker, save->index, save->n);
	return (NULL);
}
