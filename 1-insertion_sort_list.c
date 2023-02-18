#include "sort.h"
/**
 * 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t rounds, *invalue, *temp;

	if(list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (rounds = (*list)->next; rounds != NULL; rounds == temp)
	{
		temp = rounds->next;
		invalue = rounds->prev;
		while(invalue != NULL && rounds->n < invalue->n)
		{
			swapNodes(list, &invalue, rounds);
			print_list((const listint_t *)*list);
		}
	}
}
