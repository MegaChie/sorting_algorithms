#include "sort.h"
/**
 * swapValues - check code.
 * @a: integer pointer
 * @b: integer pointer
 */
void swapValues(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomotoPartition - check code.
 * @array: integer pointer
 * @size: structure variable
 * @left: integer variable
 * @right: integer variable
 * Return: up's value
 */
int lomotoPartition(int *array, size_t size, int left, int right)
{
	int center, up, down;

	center = array[right];
	for (up = left - 1; down = right + 1; up < down;)
	{
		do
		{
			up++;
		} while (array[up] < center);
		do
		{
			down--;
		} while (array[down] > center);
		if (up < down)
		{
			swapValues(array + down, array + up);
			print_array(array, size);
		}
	}
	return (up);
}

/**
 * lomotoSort - check code.
 * @array: integer pointer
 * @size: structure variable
 * @left: integer variable
 * @right: integer variable
 */
void lomotoSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomotoPartition(array, size, left, right);
		lomotoSort(array, size, left, part - 1);
		lomotoSort(array, size, part, right);
	}
}

/**
 * quick_sort - check code.
 * @array: integer pointer
 * @size: structure variable
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomotoSort(array, size, 0, size - 1);
}
