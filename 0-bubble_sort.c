#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in an ascending order
 * using bubble sort algorithm
 * @array: The array of integers
 * @size: the size of the array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	/* print array every time you swap */
	int pass, i;
	int temp, swapped = 1;

	for (pass = size -1; pass >= 0 && swapped; pass--)
	{
		swapped = 0;
		for (i = 0; i < pass; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
