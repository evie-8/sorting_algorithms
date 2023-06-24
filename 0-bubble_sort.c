#include "sort.h"
/**
* bubble_sort - sorts array using selection sort
* @array: array to be sorted
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2 || !array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1 ; j++)
		{
		if (array[j] > array[j + 1])
		{
			swapper(&array[j], &array[j + 1]);
			print_array(array, size);
		}
		}
	}
}

/**
* swapper - swaps two numbers
* @a: first num
* @b: secon num
*/
void swapper(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
