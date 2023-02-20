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
void bitMerge(int *array, size_t size, size_t start, size_t bits, char result)
{
	size_t count, hop = bits / 2;

	if (bits > 1)
	{
		for (count = start; count < start + hop; count++)
		{
			if ((result == high && array[count] > array[count + hop]) ||
				(result == low && array[count] < array[count + hop]))
			{
				swapValues(array + count, array + count + hop);
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
		bitSequance(array, size, start, cut, high);
		bitSequance(array, size, start + cut, cut, low);
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
