#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int first, second;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		second = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				first = array[j];
				array[j] = array[j + 1];
				array[j + 1] = first;
				second = 1;

				print_array(array, size);
			}
		}

		if (second == 0)
			break;
	}
}
