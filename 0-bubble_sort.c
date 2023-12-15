#include "sort.h"
/**
 *bubble_sort - Sort an array of integers in ascending order.
 * @size: size of the array
 * @array : array to be sorted
 * return : no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp;

	if (array == NULL || !size)
		return;

	x = 0;
	while (x < size)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
		x++;
	}
}
