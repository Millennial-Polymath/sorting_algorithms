#include "sort.h"
/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Partition - Recursively partitions the array using technique
 * @array: the array to be partitioned
 * @l_mkr: left marker/ lower index
 * @r_mkr: right index / higher index
 * @size: the size of the array
 *
 * Return: void
 */

void partition(int *array, int l_mkr, int r_mkr, size_t size)
{

	/* Lomuto- take the last element as the pivot */
	int pivot = array[r_mkr], i = (l_mkr - 1), j; /* index of smaller element */

	if (r_mkr <= l_mkr)
	  	return;

	for (j = l_mkr; j <= r_mkr - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++; /* increment index of the smaller element */
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[r_mkr]);
	print_array(array, size);
	partition(array, l_mkr, i, size);
	partition(array, i + 2, r_mkr, size);
}
/**
 * quick_sort - Sorts an array of integers in ascending order using
 * Quicksort algorithm
 * @array: The unsorted array
 * @size: The size of the unsorted array
 *
 * Return: Void
 */


void quick_sort(int *array, size_t size)
{
	/* take last element as the pivot */
	partition(array, 0, size - 1, size);


}
