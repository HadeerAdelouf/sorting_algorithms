#include "sort.h"

/**
 * Swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_way - lomuto partition sorting scheme imp last element is pivot
 * @array: The array of integers.
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: The final partition index.
 */
int lomuto_way(int *array, size_t size, int left, int right)
{
	int *pivot, above, low;

	pivot = array + right;
	for (above = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (above < low)
			{
				Swap(array + low, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		Swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lQ_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort
 * @size: size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 */
void lQ_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_way(array, size, left, right);
		lQ_sort(array, size, left, p - 1);
		lQ_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lQ_sort(array, size, 0, size - 1);
}
