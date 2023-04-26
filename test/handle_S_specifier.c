#include "main.h"
/**
 * handle_S - handles the %S format specifier
 * @args: list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int handle_S(va_list args, char *buffer, int buffer_index, int buff_size)
{
	char *str = va_arg(args, char *);
	int i = 0, chars_printed = 0;

	if (str == NULL)
		str = "(null)";

	for (; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			buffer_index += snprintf(buffer + buffer_index,
					buff_size - buffer_index, "\\x%02X", str[i]);
		else
			buffer[buffer_index++] = str[i];

		if (buffer_index >= buff_size)
		{
			write_buffer(buffer, buff_size, &chars_printed, &buffer_index);
		}
	}

	return (buffer_index);
}
/**
 * print_pointer - prints a pointer address in hexadecimal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_pointer(va_list args, char *buffer, int buffer_index, int buff_size)
{
	void *ptr = va_arg(args, void *);
	int chars_printed = 0;

	buffer_index += snprintf(buffer + buffer_index,
			buff_size - buffer_index, "0x%lx", (unsigned long)ptr);

	if (buffer_index >= buff_size)
	{
		write_buffer(buffer, buff_size, &chars_printed, &buffer_index);
	}

	return (buffer_index);
}

