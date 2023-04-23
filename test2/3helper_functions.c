#include "main.h"

/**
 * print_custom_str - prints the string
 * @buf_index: count variable
 * @buffer: print buffer
 * @str: string
 * Return: Nothing
 */

void print_custom_str(char *buffer, int *buf_index, const char *str)
{
	for (; *str; ++str)
	{
		if ((*str > 0 && *str < 32) || (*str >= 127))
		{
			print_char_to_buffer(buffer, buf_index, '\\');
			print_char_to_buffer(buffer, buf_index, 'x');
			print_hex_to_buffer(buffer, buf_index, *str, 1);
		}
		else
		{
			print_char_to_buffer(buffer, buf_index, *str);
		}
	}
}
