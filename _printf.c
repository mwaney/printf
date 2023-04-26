#include "main.h"

void output_buf(char buffer[], int *buff_ind);

/**
 * _printf - a function that produces output according to a format.
 * @format:character string.
 *
 *
 * Return:the number of characters printed
 */

int _printf(const char *format, ...)
{
	int  buff_ind = 0, c = 0, counter = 0, i = 0;
	int size, flags, width, precision;


	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return -1;


	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
			{
				output_buf(buffer, &buff_ind);
			}
			c++;
		}
		else
		{
			output_buf(buffer, &buff_ind);
			flags = flagged(format, &i);
			width = wide(format, &i, args);
			++i;
			precision = print_precision(format, &i, args);
			size = sizef(format, &i);

			counter = handle_format_spec(format, &i, args, buffer,
					flags, width, precision, size);

			if (counter == -1)
			{
				return (-1);
			}
			c += counter;
		}
	}
	output_buf(buffer, &buff_ind);
	va_end(args);

	return (c);
}
