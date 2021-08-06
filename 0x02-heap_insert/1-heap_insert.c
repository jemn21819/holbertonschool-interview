#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *curr1, *curr2;
	int i = 0;

	new = malloc(sizeof(heap_t));
	new->n = value;
	curr1 = *root;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	if (!curr1)
		return (new);
	curr2 = curr1;
	while (curr1)
	{
		if (curr2)
		{
			curr2 = curr2->right;
			i++;
		}
		if (curr1->left == NULL)
		{
			new->parent = curr1;
			curr1->left = new;
			break;
		}
		if (curr1->right == NULL)
		{
			new->parent = curr1;
			curr1->right = new;
			break;
		}
	}
	return (*root);
}
