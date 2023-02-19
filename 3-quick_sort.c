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
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomotoSort(array, size, 0, size - 1);
}

/**
 *
 */
int lomotoPartition(int *array, size_t size, int left, int right)
{
	int *center, up, down;

	center = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *center)
		{
			if (up < down)
			{
				swapValues(array + down, array + up);
				print_array(array, size);
			}
			up++
		}
	}
}

/**
 *
 */
void lomutoSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomotoPartition(array, size, left, right);
		lomotoSort(array, size, left, part - 1);
		lomotoSort(array, size, part + 1, right);
	}
}
