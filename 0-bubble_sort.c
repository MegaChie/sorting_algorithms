#include "sort.h"
/**
 * swapValues - check code.
 * @a: integer pointer
 * @b: integer pointer
 */
void swapValues(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - check code.
 * @array: integer pointer
 * @size: structure variable
 */
void bubble_sort(int *array, size_t size)
{
	size_t count, len = size;
	bool goOn = false;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (goOn == false)
	{
		goOn = true;
		for (count = 0; count < len - 1; count++)
		{
			if (array[count] > array[count + 1])
			{
				swapValues(array + count, array + count + 1);
				print_array(array, size);
				goOn = false;
			}
		}
		len--;
	}
}
