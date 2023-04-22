#include "main.h"
/**
 * print_char_to_buffer - prints buffer contents
 * @bufferIndex: count variable
 * @buffer: print buffer
 * @c: character
 * Return: Nothing
 */
void print_char_to_buffer(char *buffer, int *bufferIndex, char c)
{
	buffer[(*bufferIndex)++] = c;
}

/**
 * print_str_to_buffer - prints buffer contents
 * @bufferIndex: count variable
 * @buffer: print buffer
 * @str: string
 * Return: Nothing
 */
void print_str_to_buffer(char *buffer, int *bufferIndex, const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		buffer[(*bufferIndex)++] = str[i++];
	}
}


/**
 * print_num_to_buffer - prints buffer contents
 * @bufferIndex: count variable
 * @buffer: print buffer
 * @num: integer variable
 * Return: Nothing
 */
void print_num_to_buffer(char *buffer, int *bufferIndex, int num)
{
	char digitChar;

	if (num < 0)
	{
		buffer[(*bufferIndex)++] = '-';
		num = -num;
	}
	if (num / 10 > 0)
	{
		print_num_to_buffer(buffer, bufferIndex, num / 10);
	}
	digitChar = (char)(num % 10) + '0';
	buffer[(*bufferIndex)++] = digitChar;

}

/**
 * print_percent_to_buffer - prints buffer contents
 * @bufferIndex: count variable
 * @buffer: print buffer
 * Return: Nothing
 */
void print_percent_to_buffer(char *buffer, int *bufferIndex)
{
	buffer[(*bufferIndex)++] = '%';
}
~

