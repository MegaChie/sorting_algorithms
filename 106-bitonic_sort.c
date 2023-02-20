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
 * bitMerge- check code.
 * @array: integer pointer
 * @size: structure variable
 * @start: structure variable
 * @bits: structure variable
 * @result: charecter variable
 */
void bitMerge(int *array, size_t size, size_t start, size_t sequance,
		char result)
{
	size_t i, hop = sequance / 2;

	if (sequance > 1)
	{
		for (i = start; i < start + hop; i++)
		{
			if ((result == high && array[i] > array[i + hop]) ||
			    (result == low && array[i] < array[i + hop]))
			{
				swapValues(array + i, array + i + hop);
			}
		}
		bitMerge(array, size, start, hop, result);
		bitMerge(array, size, start + hop, hop, result);
	}
}

/**
 * bitSequance - check code.
 * @array: integer pointer
 * @size: structure variable
 * @start: structure variable
 * @sequance: structure variable
 * @result: charecter variable
 */
void bitSequance(int *array, size_t size, size_t start, size_t sequance,
	char result)
{
	size_t cut = sequance / 2;
	char *str = (result == high) ? "high" : "low";

	if (sequance > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequance, size, str);
		print_array(array + start, sequance);
		bitonic_seq(array, size, start, cut, high);
		bitonic_seq(array, size, start + cut, cut, low);
		bitMerge(array, size, start, sequance, result);
		printf("Result [%lu/%lu] (%s):\n", sequance, size, str);
		print_array(array + start, sequance);
	}
}
/**
 * bitonic_sort - check code.
 * @array: integer pointer
 * @size: structure variable
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitSequance(array, size, 0, size, high);
}
