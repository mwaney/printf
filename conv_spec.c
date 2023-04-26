#include "main.h"

/**
 * handle_format_spec - function to handle format specifier
 *
 * @flags: flags to apply to the format specifier
 * @width: minimum width to output
 * @precision: precision for floating point numbers
 * @size: size of the format specifier
 * @format_spec: string with the format specifier
 * @ind: pointer to the current index in the format specifier
 * @list: list of arguments passed
 * @buffer: buffer to write the output to
 *
 * Return: the number of characters printed or -1 if an error occurred
 */


int handle_format_spec(const char *format_spec, int *ind,
		va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, unknown_len = 0, printed_chars = -1;
	fm_struct conv_spec[] = {
		{'c', print_c}, {'s', print_str}, {'%', print_perc},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsalid}, {'o', print_oct}, {'x', print_hex},
		{'X', print_up_hex}, {'p', print_ptr},
		{'S', writ_S}, {'r', conv_rev}, {'R', conv_rot13},
		{'\0', NULL}
	};
	while (conv_spec[i].format_spec != '\0')
	{
		if (format_spec[*ind] == conv_spec[i].format_spec)
		{
			return (conv_spec[i].fn(list, buffer, flags,
						width, precision, size));
		}
		i++;	}
	if (conv_spec[i].format_spec == '\0')
	{
		if (format_spec[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format_spec[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			(*ind)--;
			while (*ind >= 0 && (format_spec[*ind] != ' ' &&
						format_spec[*ind] != '%'))
			{
				(*ind)--;
			}
			if (format_spec[*ind] == ' ')
			{
				(*ind)--;
			}
			return (1);	}
		unknown_len += write(1, &format_spec[*ind], 1);
		return (unknown_len);	}
	return (printed_chars);
}
/**
 * print_oct_helper - Prints an unsigned number in octal notation
 * @num: Lista of arguments
 * @buffer: Buffer array to handle print
 * @i:  Calculates active flags
 * Return: Number of chars printed
 */

int print_oct_helper(unsigned long int num, char buffer[], int i)
{
	if (num == 0)
	{
		return (i);
	}

	i = print_oct_helper(num / 8, buffer, i - 1);
	buffer[i] = (num % 8) + '0';
	return (i);
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_oct(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	VOID(width);

	num = conv_unsallid(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAGSH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (print_ud(0, i, buffer, flags, width, precision, size));
}



/**
 * print_bin - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_bin(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	VOID(buffer);
	VOID(flags);
	VOID(width);
	VOID(precision);
	VOID(size);

	n = va_arg(types, unsigned int);
	m = UINT_MAX / 2 + 1;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_unsalid - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsalid(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = conv_unsallid(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (print_ud(0, i, buffer, flags, width, precision, size));
}
