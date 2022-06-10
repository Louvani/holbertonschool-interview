#include "sort.h"

/**
 * merge_sort - start
 *@array: the array to do the sorting
 *@size: the size of the array
 */

void merge_sort(int *array, size_t size)
{

	merge_sort_res(array, 0, size - 1);
}

/**
 * merge - merge to start the serach of the array
 *@array: the array to sort
 *@left: the idx of the left size of the array
 *@middle: the midle of the aray
 *@right: the idx of the right size of the array
 */
void merge(int *array, int left, int middle, int right)
{
	int i = left, j = middle + 1, k = 0;
	int *temp;

	temp = (int *)malloc(right - (left + 1));

	while (i <= middle && j <= right)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			k += 1;
			i += 1;
		}
		else
		{
			temp[k] = array[j];
			k += 1;
			j += 1;
		}
	}
	while (i <= middle)
	{
		temp[k] = array[i];
		k += 1;
		i += 1;
	}
	while (j <= right)
	{
		temp[k] = array[j];
		k += 1;
		j += 1;
	}
	for (i = left; i <= right; i += 1)
	{
		array[i] = temp[i - left];
	}
	free(temp);
}

/**
 * merge_sort_res - res
 *@array: the array to do the sorting
 *@left: the idx of the left
 *@right: the idx of the right
 */

void merge_sort_res(int *array, int left, int right)
{
	int middle = 0;

	if (left < right)
	{
		middle = left + (right - left) / 2;

		merge_sort_res(array, left, middle);
		merge_sort_res(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}
