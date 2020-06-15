#include "sort.h"
/**
 * swap_vals - changes the values of index into an array
 * @ai: value at index i
 * @aj: value at index j
 */
void swap_vals(int *ai, int *aj)
{
	int aux;

	aux = *ai;
	*ai = *aj;
	*aj = aux;
}
/**
 * partition - function that sorts with lomuto partition
 * @array: inlet array for sorting
 * @lo: lowest limit
 * @hi: upper limit
 * @size: length of the array
 * Return: integer for partition
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int j, i;
	int pivot = array[hi];

	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_vals(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap_vals(&array[i], &array[hi]);
		print_array(array, size);
	}

	return (i);
}
/**
 * q_sort - Aux function that sorts with quick sort
 * algorithm in ascending order
 * @array: list to be sorted
 * @lo: lowest int value
 * @hi: highest int value
 * @size: lenght of the array
 */
void q_sort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		q_sort(array, lo, p - 1, size);
		q_sort(array, p + 1, hi, size);
	}
}
/**
 * quick_sort - main for data to sort
 * @array: array to be sorted
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = size - 1;

	q_sort(array, lo, hi, size);
}
