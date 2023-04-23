#include "main.h"

/**
 * print_buffer - prints buffer contents
 * @bufferIndex: count variable
 * @buffer: print buffer
 * @count: count variable
 * Return: Nothing
 */
void print_buffer(char *buffer, int *bufferIndex, int *count)
{
	buffer[*bufferIndex] = '\0';
	write(STDOUT_FILENO, buffer, *bufferIndex);
	*bufferIndex = 0;
	(*count)++;
}

/**
 * print_ud_to_buffer - prints unsigned decimal
 * @num: number to be converted
 * @bufferIndex: count variable
 * @buffer: print buffer
 * Return: Nothing
 */
void print_ud_to_buffer(char *buffer, int *bufferIndex, unsigned int num)
{
	char digitChar;

	if (num / 10 > 0)
	{
		print_num_to_buffer(buffer, bufferIndex, num / 10);
	}
	digitChar = (char)(num % 10) + '0';
	buffer[(*bufferIndex)++] = digitChar;


}
/**
 * print_oct_to_buffer - prints octal number
 * @num: number to be converted
 * @bufferIndex: count variable
 * @buffer: print buffer
 * Return: Nothing
 */

void print_oct_to_buffer(char *buffer, int *bufferIndex, unsigned int num)
{
	char digitChar;

	if (num == 0)
	{
		return;
	}

	print_oct_to_buffer(buffer, bufferIndex, num / 8);

	digitChar = (char)(num % 8) + '0';
	buffer[(*bufferIndex)++] = digitChar;
}
/**
 * print_hex_to_buffer - prints octal number
 * @num: number to be converted
 * @uppercase: variable to check if X is uppercase or lowercase
 * @bufferIndex: count variable
 * @buffer: print buffer
 * Return: Nothing
 */
void print_hex_to_buffer(char *buffer, int *bufferIndex, unsigned int num,
		int uppercase)
{
	const char *hexChars = (uppercase) ? "0123456789ABCDEF" :
		"0123456789abcdef";

	if (num == 0)
	{
		return;
	}

	print_hex_to_buffer(buffer, bufferIndex, num / 16, uppercase);
	buffer[(*bufferIndex)++] = hexChars[num % 16];
}

/**
 * print_bin_to_buffer - prints binary
 * @num: number to be converted
 * @bufferIndex: count variable
 * @buffer: print buffer
 * Return: Nothing
 */
void print_bin_to_buffer(char *buffer, int *bufferIndex, unsigned int num)
{
	char bitChar;

	if (num > 1)
	{
		print_bin_to_buffer(buffer, bufferIndex, num / 2);
	}

	bitChar = (num % 2) + '0';
	buffer[(*bufferIndex)++] = bitChar;
}

