#include "sort.h"
/**
 * swapValue - check code.
 * @a: integer pointer
 * @b: integer pointer
 */
void swapValue(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitMerge - check code.
 * @array: integer pointer
 * @size: structure variable
 * @start: structure variable
 * @sequance: structure variable
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
			if ((result == UP && array[i] > array[i + hop]) ||
			    (result == DOWN && array[i] < array[i + hop]))
				swapValue(array + i, array + i + hop);
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
void bitSequance(int *array, size_t size, size_t start, size_t sequance, char result)
{
	size_t cut = sequance / 2;
	char *str = (result == UP) ? "UP" : "DOWN";

	if (sequance > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequance, size, str);
		print_array(array + start, sequance);
		bitSequance(array, size, start, cut, UP);
		bitSequance(array, size, start + cut, cut, DOWN);
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
		return;

	bitSequance(array, size, 0, size, UP);
}
