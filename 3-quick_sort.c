#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array
 * @low: start index
 * @high: end index (pivot)
 * @size: array size
 *
 * Return: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        swap_ints(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_recursive - recursive quicksort helper
 * @array: array
 * @low: start
 * @high: end
 * @size: size
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, p - 1, size);
        quick_sort_recursive(array, p + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array using quicksort (Lomuto)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
