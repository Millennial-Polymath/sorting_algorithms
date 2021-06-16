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
 * partition - Does a recursive lomuto partition of the array
 * @array: The array to be 'partitioned'
 * @l_mkr: left marker/ lowest index
 * @r_mkr: right marker/highest index
 * @size: the size of array
 * Return: void
 */

void partition(int *array, int l_mkr, int r_mkr, size_t size)
{

	int pivot = array[r_mkr], i = (l_mkr - 1), j, swapped;
	/* check if array has one element */
	if (r_mkr <= l_mkr)
		return;

	for (j = l_mkr; j <= r_mkr - 1; j++)
	{
		/* check if the element is smaller than the pivot */
		if (array[j] < pivot)
		{
			/* increment the index of the smaller no. */
			i++;
			swapped = swap(&array[i], &array[j]);
		}
	}
	/* swap the ith + 1 with the pivot */
	swapped = swap(&array[i + 1], &array[r_mkr]);
	if  (swapped)
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
