

#include "main.h"


/**
 * prefix_hex - Appends the hexadecimal code of an ASCII character.
 *
 * @buffer:buffer to which to append the hexadecimal code.
 * @index:  index at which to start.
 * @codex: ASSCI CODE.
 * Return: 3 (length of the hexadecimal representation and prefix)
 */
int prefix_hex(char codex, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	if (codex < 0)
		codex *= -1;
	buffer[index++] = '\\';
	buffer[index++] = 'x';
	buffer[index++] = map_to[codex / 16];
	buffer[index] = map_to[codex % 16];

	return (3);
}

/**
 * print_precision - Calculates the printing precision
 * @format: Pointer to index of current character in format string
 * @i: List of arg
 * @args:args args
 *
 * Return: integer.
 */
int print_precision(const char *format, int *i, va_list args)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	curr_i++;

	while (format[curr_i] != '\0')
	{
		if (bool_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

/**
 * sizef -  rgument for formatting
 *
 * @i: Pointer
 * @format: va list args
 * Return: integer
 *
 */
int sizef(const char *format, int *i)
{
	int curr_i = *i + 1;
	int parse_s = 0;

	parse_s = (format[curr_i] == 'l') ? SLS : ((format[curr_i] == 'h') ? CLS : 0);

	*i = (parse_s == 0) ? curr_i - 1 : curr_i;

	return (parse_s);
}


/**
 * wide - extracts the width specifier
 * @i: pointer to the current index
 * @args: va_list of arguments
 * @format: pointer to the format string
 *
 * Return: integer representing the width specifier
 */

int wide(const char *format, int *i, va_list args)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (bool_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}



