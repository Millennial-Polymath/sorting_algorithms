#include "sort.h"
/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: void
 */
int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return (1);
}

/**
 * partition - Partitions an array
 * @start: The start index
 * @end: The last idex
 * @arr: The array that is being sorted
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
void partition(int *arr, int start, int end, size_t size)
{

	int pivot = arr[end], i = start - 1, j;

	if (start > end)
		return;

	for (j = start; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[j], &arr[i]);
				print_array(arr, size);
			}
		}
	}
	if (end != i + 1)
	{
		swap(&arr[i + 1], &arr[end]);
		print_array(arr, size);
	}

	partition(arr, start, i, size);
	partition(arr, i + 2, end, size);
}

/**
 * quick_sort - performs the quick sort recursively
 * @array: The array we are sorting
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}
