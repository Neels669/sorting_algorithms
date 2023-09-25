#include "sort.h"

/**
 * lomuto - Implements the Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @second: The lower index of the partition
 * @first: The higher index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element after partitioning
 */
size_t lomuto(int *array, ssize_t second, ssize_t first, size_t size)
{
	int temp;
	int pivot = array[first];
	ssize_t i = second - 1, j;

	for (j = second; j <= first - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != first)
	{
		int temp;

		temp = array[i + 1];

		array[i + 1] = array[first];

		array[first] = temp;

		print_array(array, size);
	}

	return (i + 1);
}

/**
 * sort_rec - Recursively sorts an array using Quick Sort
 *
 * @array: The array to be sorted
 * @second: The lower index of the partition
 * @first: The higher index of the partition
 * @size: Number of elements in @array
 */
void sort_rec(int *array, ssize_t first, ssize_t second, size_t size)
{
	size_t i;

	if (second < first)
	{
		i = lomuto(array, second, first, size);

		sort_rec(array, second, i - 1, size);
		sort_rec(array, i + 1, first, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_rec(array, 0, size - 1, size);
}



