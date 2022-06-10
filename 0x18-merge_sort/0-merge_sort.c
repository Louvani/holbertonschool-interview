#include "sort.h"

/**
 * merge_sort - start
 *@array: the array to do the sorting
 *@size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (array && size >= 2)
	{
		divide_array(array, 0, size - 1);
	}
}

/**
 * merge - Merge subarrays
 * @array: Pointer to array of integers
 * @start: First index of left subarray
 * @mid: Last index of left subarray
 * @end: Last index of right subarray
 * Return: None
 */
void merge(int *array, int start, int mid, int end)
{
	int left_iter, right_iter;
	int left_size = mid - start + 1;
	int right_size = end - mid;

#pragma GCC diagnostic ignored "-Wvla"
	int left[left_size];
	int right[right_size];

	for (left_iter = 0; left_iter < left_size; left_iter++)
		left[left_iter] = array[start + left_iter];
	for (right_iter = 0; right_iter < right_size; right_iter++)
		right[right_iter] = array[mid + right_iter + 1];

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	sort(array, left, right, start, mid, end);

	printf("[Done]: ");
	print_array(&array[start], left_size + right_size);
}

/**
 * divide_array - Split array into subarrays
 * @array: Pointer to array of integers
 * @start: First index of left subarray
 * @end: Last index of right subarray
 *
 * Return: None
 */
void divide_array(int *array, int start, int end)
{
	int mid = (start + end - 1) / 2;

	if (start < end)
	{
		divide_array(array, start, mid);
		divide_array(array, mid + 1, end);

		merge(array, start, mid, end);
	}
}


/**
 * sort - Sort
 * @arr: Pointer to array of integers
 * @l: Pointer to left subarray
 * @r: Pointer to right subarray
 * @start: First index of left subarray
 * @mid: Last index of left subarray
 * @end: Last index of right subarray
 *
 * Return: None
 */
void sort(int *arr, int *l, int *r, int start, int mid, int end)
{
	int left_iter, right_iter, array_iter;
	int left_size = mid - start + 1;
	int right_size = end - mid;

	left_iter = right_iter = 0;
	array_iter = start;

	while (left_iter < left_size && right_iter < right_size)
	{
		if (l[left_iter] < r[right_iter])
		{
			arr[array_iter] = l[left_iter];
			left_iter++;
		}
		else
		{
			arr[array_iter] = r[right_iter];
			right_iter++;
		}
		array_iter++;
	}

	while (left_iter < left_size)
	{
		arr[array_iter] = l[left_iter];
		left_iter++;
		array_iter++;
	}

	while (right_iter < right_size)
	{
		arr[array_iter] = r[right_iter];
		right_iter++;
		array_iter++;
	}
}
