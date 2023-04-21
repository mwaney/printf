#include "main.h"

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

	va_start(argList, format);

	while (*string != '\0')
	{
		if (*string == '%')
		{
			string = handle_switch(string + 1, argList, &count);
		}
		else
		{
			print_char(*string, &count);
		}

		string++;
	}

	va_end(argList);
	return (count);
}
/**
 * print_char - a function that prints a character
 * @c: a character
 * @count: a variable to keep count
 * Return: Nothing
 */
void print_char(char c, int *count)
{
	_putchar(c);
	(*count)++;
}
/**
 * handle_switch - a function that contains the switch statement
 * @string: a character array
 * @argList: list of arguments
 * @count: a variable to keep count
 * Return: Nothing
 */
const char *handle_switch(const char *string, va_list argList, int *count)
{
	switch (*string)
	{
		case 'c':
			print_char(va_arg(argList, int), count);
			break;
		case 's':
			print_str(va_arg(argList, const char *), count);
			break;
		case 'i':
		case 'd':
			print_num(va_arg(argList, int), count);
			break;
		case 'b':
			print_bin(va_arg(argList, unsigned int), count);
			break;
		case 'u':
			print_ud(va_arg(argList, unsigned int), count);
			break;
		case 'o':
			print_oct(va_arg(argList, unsigned int), count);
			break;
		case 'x':
		case 'X':
			print_hex(va_arg(argList, unsigned int),
					(*string == 'X'), count);
			break;
		case '%':
			print_char('%', count);
			break;
		default:
			print_char('%', count);
			print_char(*string, count);
			break;
	}
	return (string);
}
/**
 * print_str- a function that prints a string
 * @s: a character array
 * @count: a variable to keep count
 * Return: Nothing
 */
void print_str(const char *s, int *count)
{
	if (!s)
	{
		s = "(null)";
	}

	while (*s != '\0')
	{
		_putchar(*s);
		(*count)++;
		s++;
	}
}
/**
 * print_num - a function that produces output according to a format
 * @count: counter
 * @x: integer
 * Return: Nothing
 */
void print_num(int x, int *count)
{
	if (x < 0)
	{
		_putchar('-');
		x = -x;
		(*count)++;
	}
	if (x >= 10)
	{
		print_num(x / 10, count);
	}
	_putchar(x % 10 + '0');
	(*count)++;
}

