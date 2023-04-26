#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int buffer_index = 0, chars_printed = 0;
	char buffer[BUFFER_SIZE];

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format += handle_format_specifier(format, args, buffer,
					&buffer_index, BUFFER_SIZE, &chars_printed);
		}
		else
		{
			buffer[buffer_index++] = *format++;
			if (buffer_index >= BUFFER_SIZE)
			{
				write_buffer(buffer, BUFFER_SIZE, &chars_printed, &buffer_index);
			}
		}
	}

	write_buffer(buffer, BUFFER_SIZE, &chars_printed, &buffer_index);

	va_end(args);

	return (chars_printed);
}
