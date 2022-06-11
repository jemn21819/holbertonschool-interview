#include "sort.h"

/**
 * heap - Finds the biggest element
 * @array: Pointer to array
 * @n: size of array
 * @i: index
 * @size: size
 */
void heap(int *array, size_t n, int i, size_t size)
{
	int bgr = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int tmp;

	if (l < (int) n && array[l] > array[bgr])
		bgr = l;

	if (r < (int) n && array[r] > array[bgr])
		bgr = r;

	if (bgr != i)
	{
		tmp = array[i];

		array[i] = array[bgr];
		array[bgr] = tmp;
		print_array(array, size);
		heap(array, n, bgr, size);
	}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: Pointer to array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (size == 0)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heap(array, i, 0, size);
	}
}
