#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - print thr grid
 * @grid: the grid to print
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * tople - resolve the grid.
 * @grid1:
 *
 */

void tople(int grid1[3][3])
{
	int grid[3][3], i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = grid1[i][j];
	}
	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 3; k++)
		{
			if (grid[i][k] > 3)
			{
				grid1[i][k] -= 4;
				if (i + 1 < 3)
					grid1[i + 1][k] += 1;
				if (k + 1 < 3)
					grid1[i][k + 1] += 1;
				if (i - 1 >= 0)
					grid1[i - 1][k] += 1;
				if (k - 1 >= 0)
					grid1[i][k - 1] += 1;
			}
		}
	}
}


/**
 * stable - check if the grid is stable
 * @grid1: the grid to check
 * Return: 1 if stable 0 if not
 */
int stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - function add 2 grid
 * @grid1: the first grid
 * @grid2: the second grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		tople(grid1);
	}
}
