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
void bitMerge(int *array, size_t size, size_t start, size_t seq,
		char result)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((result == high && array[i] > array[i + jump]) ||
			    (result == low && array[i] < array[i + jump]))
				swapValues(array + i, array + i + jump);
		}
		bitMerge(array, size, start, jump, result);
		bitMerge(array, size, start + jump, jump, result);
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
void bitSequance(int *array, size_t size, size_t start, size_t seq, char result)
{
	size_t cut = seq / 2;
	char *str = (result == high) ? "high" : "low";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitSequance(array, size, start, cut, high);
		bitSequance(array, size, start + cut, cut, low);
		bitMerge(array, size, start, seq, result);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
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
