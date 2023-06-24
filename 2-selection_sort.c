#include "sort.h"
/**
* selection_sort - sorts array using selection sort
* @array: array to be sorted
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int smallest;

	if (size <= 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
		if (array[j] < smallest)
			{
			smallest = array[j];
			pos = j;
			}
		}
		if (pos != i)
		{
			array[pos] = array[i];
			array[i] = smallest;
			print_array(array, size);
		}
	}
}
