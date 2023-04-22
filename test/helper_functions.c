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
/**
 * print_ud - prints unsigned decimal
 * @num: number to be converted
 * @count: count variable
 * Return: Nothing
 */
void print_ud(unsigned int num, int *count)
{
	if (num / 10 > 0)
	{
		print_ud((num / 10), count);
	}
	print_char((num % 10 + '0'), count);
}
/**
 * print_oct - prints octal number
 * @num: number to be converted
 * @count: count variable
 * Return: Nothing
 */
void print_oct(unsigned int num, int *count)
{
	if (num / 8 > 0)
	{
		print_oct((num / 8), count);
	}
	print_char((num % 8 + '0'), count);
}
/**
 * print_hex - prints octal number
 * @num: number to be converted
 * @uppercase: variable to check if X is uppercase or lowercase
 * @count: count variable
 * Return: Nothing
 */
void print_hex(unsigned int num, int uppercase, int *count)
{
	int character;
	char hexChar;

	if (num == 0)
	{
		return;
	}
	character = num % 16;
	if (character < 10)
	{
		hexChar = character + '0';
	}
	else
	{
		hexChar = (uppercase ? 'A' : 'a') + (character - 10);
	}
	print_hex((num / 16), uppercase, count);
	print_char(hexChar, count);

}
