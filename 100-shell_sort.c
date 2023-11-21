#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using Shell Sort algorithm with Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Generate Knuth sequence: 1, 4, 13, 40, 121, ... */
	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}

		/* Print the array when decreasing the interval */
		print_array(array, size);

		interval = (interval - 1) / 3;
	}
}
