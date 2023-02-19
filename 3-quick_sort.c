#include "sort.h"
void swapValues(int *a, int *b);
int lomotoPartition(int *array, size_t size, int left, int right);
void lomotoSort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
			up++;
		}
	}
	if (array[up] > *center)
	{
		swapValues(array + down, array + up);
		print_array(array, size);
	}
	return (up);
}

/**
 *
 */
void lomotoSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomotoPartition(array, size, left, right);
		lomotoSort(array, size, left, part - 1);
		lomotoSort(array, size, part + 1, right);
	}
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
