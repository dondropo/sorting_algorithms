#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the linked list
 *
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nodefor_swap, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	nodefor_swap = (*list)->next;
	while (nodefor_swap != NULL)
	{
		next_swap = nodefor_swap->next;
		while (nodefor_swap->prev != NULL && nodefor_swap->prev->n > nodefor_swap->n)
		{
			nodefor_swap->prev->next = nodefor_swap->next;
			if (nodefor_swap->next != NULL)
				nodefor_swap->next->prev = nodefor_swap->prev;
			nodefor_swap->next = nodefor_swap->prev;
			nodefor_swap->prev = nodefor_swap->next->prev;
			nodefor_swap->next->prev = nodefor_swap;
			if (nodefor_swap->prev == NULL)
				*list = nodefor_swap;
			else
				nodefor_swap->prev->next = nodefor_swap;
			print_list(*list);
		}
		nodefor_swap = next_swap;
	}
}
