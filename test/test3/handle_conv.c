#include "main.h"

int handle_format_specifier(const char *format, va_list args, char *buffer,
		int *buffer_index, int buff_size, int *chars_printed)
{
	int width = 0, precision = -1;
	char flags[5] = {0};
	int flags_index = 0;
	int specifier_size = 0;

	while (*format != '\0')
	{
		if (*format == '-')
		{
			flags[flags_index++] = '-';
			format++;
		}
		else if (*format == '0')
		{
			flags[flags_index++] = '0';
			format++;
		} else
		{
			break;
		}
	}

	if (*format >= '1' && *format <= '9')
	{
		width = get_number(&format);
	}

	if (*format == '.')
	{
		format++;
		precision = get_number(&format);
	}

	switch (*format)
	{
		case 'c':
			specifier_size = print_chars(args, buffer, *buffer_index, buff_size,
					width, precision, flags);
			break;
		case 's':
			specifier_size = print_string(args, buffer, *buffer_index, buff_size,
					width, precision, flags);
			break;
		case 'd':
		case 'i':
			specifier_size = print_integer(args, buffer, *buffer_index, buff_size,
					width, precision, flags);
			break;
		default:
			buffer[*buffer_index] = *format;
			(*buffer_index)++;
			specifier_size++;
			break;
	}

	(*chars_printed) += specifier_size;
	(*buffer_index) += specifier_size;

	return specifier_size;
}

int get_number(const char **format)
{
	int num = 0;

	while (**format >= '0' && **format <= '9') {
		num = num * 10 + (**format - '0');
		(*format)++;
	}

	return num;
}

