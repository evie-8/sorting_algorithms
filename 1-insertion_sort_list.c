#include "sort.h"
/**
 * insertion_sort_list - sorts list or array using insertion sort
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *swap, *ptr;
	int i;

	if (*list == NULL || list == NULL)
		return;
	ptr = *list;
	swap = *list;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i < 2)
		return;
	ptr = *list;
	while (ptr && ptr->next)
	{
		if (ptr->next->n < ptr->n)
		{
			swap = ptr->next;
			ptr->next = ptr->next->next;
			ptr->next->next = ptr;
			ptr = swap;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}

