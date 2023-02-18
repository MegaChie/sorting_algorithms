#include "sort.h"
/**
 * 
 */
void swapValues(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void swapNodes(listint_t **h, listint_t **node1, listint_t node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else:
	{
		*h = node2;
	}
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
