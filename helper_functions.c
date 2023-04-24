#include "main.h"
/**
 * print_char - prints a single character
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * Return: updated index in buffer
 */
int print_char(va_list args, char *buffer, int buffer_index)
{
	char c = va_arg(args, int);

	buffer[buffer_index++] = c;

	return (buffer_index);
}

/**
 * print_string - prints a string
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_string(va_list args, char *buffer, int buffer_index, int buff_size)
{
	char *s = va_arg(args, char *);
	int len = snprintf(buffer + buffer_index,
			buff_size - buffer_index, "%s", s);
	buffer_index += len;

	return (buffer_index);
}

/**
 * write_buffer - writes the contents of the buffer to stdout
 * @buffer: buffer to write
 * @buffer_size: size of buffer
 * @chars_printed: pointer to the total number of characters printed
 * @buffer_index: pointer to the current index in the buffer
 */
void write_buffer(char *buffer, int buffer_size,
		int *chars_printed, int *buffer_index)
{
	*chars_printed += write(1, buffer, *buffer_index);
	*buffer_index = 0;

	(void)buffer_size;
}

/**
 * handle_format_specifier - handles a format specifier
 * @format: format string
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: pointer to the current index in the buffer
 * @buff_size: size of buffer
 * @chars_printed: pointer to the total number of characters printed
 * Return: updated index in buffer
 */
int handle_format_specifier(const char *format, va_list args,
		char *buffer, int *buffer_index, int buff_size,
		int *chars_printed)
{
	switch (format[1])
	{
		case 'c':
			*buffer_index = print_char(args, buffer, *buffer_index);
			break;
		case 's':
			*buffer_index = print_string(args, buffer, *buffer_index, buff_size);
			break;
		case '%':
			buffer[(*buffer_index)++] = '%';
			break;
		case 'd':
		case 'i':
			*buffer_index = print_integer(args, buffer, *buffer_index, buff_size);
			break;
		case 'b':
			*buffer_index = print_binary(args, buffer, *buffer_index, buff_size);
			break;
		case 'u':
			*buffer_index = print_ud(args, buffer, *buffer_index, buff_size, 10, 0);
			break;
		case 'o':
			*buffer_index = print_octal(args, buffer, *buffer_index, buff_size);
			break;
		case 'x':
			*buffer_index = print_hex(args, buffer, *buffer_index, buff_size);
			break;

		case 'X':
			*buffer_index = print_hex_uppercase(args, buffer, *buffer_index, buff_size);
			break;
		default:
			break;
	}
	if (*buffer_index >= BUFFER_SIZE)
		write_buffer(buffer, BUFFER_SIZE, chars_printed, buffer_index);
	return (2);
}

/**
 * print_buffered_string - prints a string that may be larger than the buffer
 * @format: format string
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: pointer to the current index in the buffer
 * @buff_size: size of buffer
 * @chars_printed: pointer to the total number of characters printed
 */
void print_buffered_string(const char *format, va_list args,
		char *buffer, int *buffer_index, int buff_size,
		int *chars_printed)
{
	int i = 0, j, len;
	char *str;

	while (format[i])
	{
		if (format[i] == '%')
		{
			len = handle_format_specifier(format + i, args, buffer,
					buffer_index, buff_size, chars_printed);
			i += len;
		}
		else
		{
			j = 0;
			str = buffer + (*buffer_index);
			while (format[i + j] && format[i + j] != '%')
			{
				str[j] = format[i + j];
				j++;
				if ((*buffer_index) + j >= BUFFER_SIZE)
				{
					write_buffer(buffer, BUFFER_SIZE, chars_printed, buffer_index);
					str = buffer + (*buffer_index);
				}
			}
			str[j] = '\0';
			(*buffer_index) += j;
			i += j;
		}
	}
	write_buffer(buffer, BUFFER_SIZE, chars_printed, buffer_index);

}
