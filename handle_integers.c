#include "main.h"

/**
 * print_integer - prints an integer
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_integer(va_list args, char *buffer, int buffer_index, int buff_size)
{
	int num = va_arg(args, int);
	int len = snprintf(buffer + buffer_index,
			buff_size - buffer_index, "%d", num);
	buffer_index += len;

	return (buffer_index);
}
/**
 * print_binary - prints an integer in binary
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_binary(va_list args, char *buffer, int buffer_index, int buff_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	char binary[33];

	for (i = 31; i >= 0; i--)
	{
		binary[i] = (num & 1) + '0';
		num >>= 1;
	}
	binary[32] = '\0';

	i = 0;
	while (binary[i] == '0' && i < 31)
		i++;

	len = snprintf(buffer + buffer_index,
			buff_size - buffer_index, "%s", &binary[i]);
	if (len > buff_size - buffer_index)
	{
		len = snprintf(buffer + buffer_index,
				buff_size - buffer_index, "%s", &binary[32 - (buff_size - buffer_index)]);
	}
	buffer_index += len;

	return (buffer_index);
}
