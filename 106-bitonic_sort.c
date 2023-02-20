#include "sort.h"
/**
 * swapValue - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swapValue(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitMerge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sequance: The size of the sequence to sort.
 * @result: The direction to sort in.
 */
void bitMerge(int *array, size_t size, size_t start, size_t sequance,
		char result)
{
	size_t i, jump = sequance / 2;

	if (sequance > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((result == UP && array[i] > array[i + jump]) ||
			    (result == DOWN && array[i] < array[i + jump]))
				swapValue(array + i, array + i + jump);
		}
		bitMerge(array, size, start, jump, result);
		bitMerge(array, size, start + jump, jump, result);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sequance: The size of a block of the building bitonic sequence.
 * @result: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t sequance, char result)
{
	size_t cut = sequance / 2;
	char *str = (result == UP) ? "UP" : "DOWN";

	if (sequance > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequance, size, str);
		print_array(array + start, sequance);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitMerge(array, size, start, sequance, result);

		printf("Result [%lu/%lu] (%s):\n", sequance, size, str);
		print_array(array + start, sequance);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
