#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto - Implements Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The final position of the pivot element
 */
size_t lomuto(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t j, i = low - 1;

	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Recursively sorts an array using Quick Sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @size: Number of elements in @array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pi = lomuto(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
