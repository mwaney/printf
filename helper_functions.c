#include "main.h"
/**
 * print_bin - prints bianry
 * @num: number to be converted
 * @count: count variable
 * Return: Nothing
 */

void print_bin(unsigned int num, int *count)
{
	int i, j;
	int *binary;

	if (num == 0)
	{
		print_char('0', count);
		return;
	}
	binary = malloc(sizeof(int) * 32);
	if (!binary)
		return;
	i = 0;
	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print_char(binary[j] + '0', count);
	}
	free(binary);
}

