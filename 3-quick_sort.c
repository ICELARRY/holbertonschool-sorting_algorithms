#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first int pointer
 * @b: second int pointer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: array of integers
 * @low: start index
 * @high: end index
 * @size: size of array
 *
 * Return: partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
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
 * quick_sort_recursive - recursive quick sort function
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
