#include "main.h"
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * _printf - a function that produces output according to a format
 * @format: a character string
 * Return: number of characters printed
 */

int _printf(const char * const format, ...)
{
	va_list argList;
	const char *string = format;
	int count = 0;
	char buffer[1024];
	int buf_index = 0;

	va_start(argList, format);

	while (*string != '\0')
	{
		if (*string == '%')
		{
			if (*(string + 1) == '%')
			{
				print_char_to_buffer(buffer, &buf_index, '%');
				string += 2;
				count++;
				continue;
			}
			else
			{
				string = handle_switch(string + 1, argList,
						&count, buffer, &buf_index);
			}
		}
		else
		{
			if (buf_index == BUFFER_SIZE)
			{
				write(1, buffer, buf_index);
				buf_index = 0;
			}
			print_char_to_buffer(buffer, &buf_index, *string);
			count++;
		}
		string++;
	}
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
	}

	va_end(argList);
	return (count);
}
/**
 * handle_switch - a function that contains the switch statement
 * @string: a character array
 * @argList: list of arguments
 * @count: a variable to keep count
 * @buffer: pointer to buffer
 * @buf_index: index of the buffer
 * Return: character pointer
 */
const char *handle_switch(const char *string, va_list argList,
		int *count, char *buffer, int *buf_index)
{
	switch (*string)
	{
		case 'c':
			print_char_to_buffer(buffer, buf_index, va_arg(argList, int));
			break;
		case 's':
			print_str_to_buffer(buffer, buf_index,
					va_arg(argList, const char *));
			break;
		case 'i':
		case 'd':
			print_num_to_buffer(buffer, buf_index,
					va_arg(argList, int));
			break;
		case 'b':
			print_bin_to_buffer(buffer, buf_index,
					va_arg(argList, unsigned int));
			break;
		case 'u':
			print_ud_to_buffer(buffer, buf_index,
					va_arg(argList, unsigned int));
			break;
		case 'o':
			print_oct_to_buffer(buffer, buf_index,
					va_arg(argList, unsigned int));
			break;
		case 'x':
		case 'X':
			print_hex_to_buffer(buffer, buf_index,
					va_arg(argList, unsigned int), (*string == 'X'));

			break;
		case 'S':
			print_custom_str(buffer, buf_index, va_arg(argList,
						const char *));
			break;
		case '%':
			print_percent_to_buffer(buffer, buf_index);
			break;
		default:
			print_char_to_buffer(buffer, buf_index, '%');
			print_char_to_buffer(buffer, buf_index, *string);

			break;
	}

	if (*buf_index == BUFFER_SIZE - 1)
		print_buffer(buffer, buf_index, count);
	return (string);
}
