#include "sort.h"
/**
 * bubble_sort : sorts all array elements by ascending order
 * @size: size of the array
 * @array : array to be sorted
 * return : no return
 */
void bubble_sort(int *array, size_t size)
{
    size_t x, y;
    int tmp;

    if (array == NULL || size == NULL)
		return;

    x = 0;
    while (x < size)
    {
        for (y = 0; y < size - 1; y++)
        {
            if (array[y] > array[y + 1])
            {
                tmp = array[y];
                array[y] = array[y + 1];
                tmp = array[y + 1];
                print_array(array, size);
            }
        }
        x++;
    }
}