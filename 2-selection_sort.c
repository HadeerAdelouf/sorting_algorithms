#include "sort.h"
/**
 * selection_sort -sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, ele, X = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		X = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
				X += 1;
			}
		}
		ele = array[i];
		array[i] = array[temp];
		array[temp] = ele;
		if (X != 0)
			print_array(array, size);
	}
}
