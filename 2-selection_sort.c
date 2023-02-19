#include "sort.h"
/**
 *
 */
void swapvalues(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t raw, collumn;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (raw = 0; raw < size - 1; raw++)
	{
		mini = array + raw;
		for (collumn = raw + 1; collumn < size; collumn++)
		{
			mini = (array[collumn] < *mini) ? (array + collumn) : mini;
		}
		if ((array + raw) != mini)
		{
			swapvalues(array + raw, mini);
			print_array(array, size);
		}
	}
}
