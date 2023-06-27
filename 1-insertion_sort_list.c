#include "sort.h"
/**
 * insertion_sort_list - sorts list or array using insertion sort
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	int *array, p, i, j;
	int size;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	array = to_array(list, &size);
	if (array == NULL)
		return;
	printf("%d\n", size);
	for (i = 1; i < size; i++)
	{
		p = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > p)
		{
			swapper(&array[j + 1], &array[j]);
			print_array(array, size);
			j = j - 1;
		}
		array[j + 1] = p;
	}
	*list = creat_listint(array, size);
}

/**
* to_array - convert linked list to array
* @list: list to be converted
* @s: size
* Return: array
*/
int *to_array(listint_t **list, int *s)
{
	int i = 0, *array, j = 0;
	listint_t *ptr;

	if (list == NULL || (*list) == NULL)
		return (NULL);
	ptr = *list;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	array = malloc(sizeof(int) * i);
	if (array == NULL)
		return (NULL);
	ptr = *list;
	while (ptr)
	{
		array[j] = ptr->n;
		ptr = ptr->next;
		j++;
	}
	*s = j;
	return (array);
}

/**
* creat_listint - Creates a doubly linked list from an array of integers
*
* @array: Array to convert to a doubly linked list
* @size: Size of the array
*
* Return: Pointer to the first element of the created list. NULL on failure
*/
listint_t *creat_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
	if (list->next)
		list->next->prev = list;
	}
	return (list);
}

/**
* print_array - Prints an array of integers
*
* @array: The array to be printed
* @size: Number of elements in @array
*/
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
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
