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
