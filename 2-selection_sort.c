#include "sort.h"
/**
 * selection_sort - SOrts an array of integers in an ascending
 * order using selection sort algorithm
 * @array: the unsorted array of integers
 * @size: the size of the array
 *
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp, flag;


	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		/* make the index for the min value to be i */
		min = i;
		/* loop thru comparing minth item with the jth item */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				flag = 1;
			}

		/* swap the elements */
		}
		if (flag == 1)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		flag = 0;
	}


}
