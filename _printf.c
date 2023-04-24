#include "main.h"
#define BUFFER_SIZE 1024

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	va_list args;

	char buffer[BUFFER_SIZE], c;
	int buffer_index = 0, len;
	int format_index = 0;
	int chars_printed = 0;
	char *s;

	va_start(args, format);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%')
		{
			format_index++;
			switch (format[format_index])
			{
				case 'c':
					c = va_arg(args, int);
					buffer[buffer_index++] = c;
					break;
				case 's':
					s = va_arg(args, char *);
					len = snprintf(buffer + buffer_index,
							BUFFER_SIZE - buffer_index, "%s", s);
					buffer_index += len;
					break;
				case '%':
					buffer[buffer_index++] = '%';
					break;
			}
		}
		else
		{
			buffer[buffer_index++] = format[format_index];
		}

		format_index++;

		if (buffer_index >= BUFFER_SIZE)
		{
			chars_printed += write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}

	if (buffer_index > 0)
	{
		chars_printed += write(1, buffer, buffer_index);
	}

	va_end(args);

	return (chars_printed);
}
