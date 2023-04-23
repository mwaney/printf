#include "main.h"

/**
 * handle_integer - Handles integer specifiers for printf
 * @spec: The specifier character
 * @argList: The variable argument list
 * @buffer: The output buffer
 * @buf_index: A pointer to the current index in the output buffer
 * Return: Nothing
 */
void handle_integer(char spec, va_list argList, char *buffer, int *buf_index)
{
	switch (spec)
	{
		case 'i':
		case 'd':
			print_num_to_buffer(buffer, buf_index, va_arg(argList, int));
			break;
		case 'b':
			print_bin_to_buffer(buffer, buf_index, va_arg(argList, unsigned int));
			break;
		case 'u':
			print_ud_to_buffer(buffer, buf_index, va_arg(argList, unsigned int));
			break;
		case 'o':
			print_oct_to_buffer(buffer, buf_index, va_arg(argList, unsigned int));
			break;
		case 'x':
		case 'X':
			print_hex_to_buffer(buffer, buf_index, va_arg(argList, unsigned int),
					spec == 'X');
			break;
	}
}

/**
 * handle_switch_case - Handles switch cases for printf
 * @spec: The specifier character
 * @argList: The variable argument list
 * @buffer: The output buffer
 * @buf_index: A pointer to the current index in the output buffer
 * Return: Nothing
 */
void handle_switch_case(char spec, va_list argList,
		char *buffer, int *buf_index)
{
	switch (spec)
	{
		case 'c':
			print_char_to_buffer(buffer, buf_index, va_arg(argList, int));
			break;
		case 's':
			print_str_to_buffer(buffer, buf_index, va_arg(argList, const char *));
			break;
		case 'S':
			print_custom_str(buffer, buf_index, va_arg(argList, const char *));
			break;
		case '%':
			print_percent_to_buffer(buffer, buf_index);
			break;
		default:
			print_char_to_buffer(buffer, buf_index, '%');
			print_char_to_buffer(buffer, buf_index, spec);
			break;
	}
}

