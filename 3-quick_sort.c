#include "sort.h"
/**
* quick_sort - sort using quick sort algorithm
* @array: array to be sorted
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	size_t partitioned;

	if (!array || size < 2)
		return;
	print_sort(array, size, 1);
	partitioned = lomutu(array, size);
	quick_sort(array, partitioned);
	quick_sort(array + partitioned, size - partitioned);
}

/**
* lomutu - partition using lomutu scheme
* @array: array to be partitioned
* @size: lowest index
* Return: j + 1
*/
size_t lomutu(int *array, size_t size)
{
	int pivot;
	size_t i, j, high = size - 1, low = 0;

	pivot = array[high];
	j = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				swapper(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
			j++;
		}
	}
	if (j != high)
	{
		swapper(&array[j], &array[high]);
		print_sort(array, size, 0);
	}
	return (j);
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
/**
 * print_sort - prints properly
 * @array: Array to be printed
 * @size: Size of array
 * @start: initializer of array
 */
void print_sort(int array[], size_t size, int start)
{
	static int *ptr = (void *)0;
	static size_t real_size;

	if (!ptr && start)
	{
		ptr = array;
		real_size = size;
	}
	if (!start)
		print_array(ptr, real_size);
}
