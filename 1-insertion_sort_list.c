#include "sort.h"
/**
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t rounds, *invalue, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (rounds = (*list)->next; rounds != NULL; rounds = temp)
	{
		temp = rounds->next;
		invalue = rounds->prev;
		while (invalue != NULL && rounds->n < invalue->n)
		{
			swapNodes(list, &invalue, rounds);
			print_list((const listint_t *)*list);
		}
	}
}

void swapNodes(listint_t **h, listint_t **node1, listint_t node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
	{
		*h = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
