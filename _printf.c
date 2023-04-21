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
			string++;
			switch (*string)
			{
				case 'c':
					_putchar(va_arg(argList, int));
					count++;
					break;
				case 'i':
				case 'd':
					print_num(va_arg(argList, int),
							&count);
					break;
				case 's':
					{
						const char *s = va_arg(argList,
								const char *);
						if (s == NULL)
						{
							s = "(null)";
						}
						while (*s != '\0')
						{
							_putchar(*s);
							count++;
							s++;
						}
					break;
					}
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(*string);
					count++;
					break;
			}
		}
		else
		{
			_putchar(*string);
			count++;
		}

		string++;
	}

	va_end(argList);
	return (count);
}

/**
 * print_num - a function that produces output according to a format
 * @count: counter
 * @x: integer
 * Return: number of characters printed
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

