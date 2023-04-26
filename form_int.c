#include "main.h"

/**
 * change_num_size - the len of an integer
 *
 * @cast_size: cast len (SLS, CLS, or default)
 * @num: integer
 * Return: Casted value
 */
long int change_num_size(long int num, int cast_size)
{
	switch (cast_size)
	{
		case SLS:
			return (num);
		case CLS:
			return ((short) num);
		default:
			return ((int) num);
	}
}
/**
 * conv_unsallid -Casts an unsigned integer to the specified cast_size
 * @num: integer
 * @cast_size:cast len
 *
 * Return: ineteger
 */
long int conv_unsallid(unsigned long int num, int cast_size)
{
	if (cast_size == SLS)
		return (num);
	else if (cast_size == CLS)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
/**
 * print_int - Print int
 *
 * @width: get width.
 * @p_mod: Precision specification
 * @len: Size specifier
 * @types: Lista of arguments
 * @char_buff: Buffer array to handle print
 * @flag:  Calculates active flag
 * Return: Number of chars printed
 */
int print_int(va_list types, char char_buff[],
		int flag, int width, int p_mod, int len)
{
	int i = BUFFER_SIZE - 2;
	int neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = change_num_size(n, len);

	if (n == 0)
		char_buff[i--] = '0';

	char_buff[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		neg = 1;
	}

	while (num > 0)
	{
		char_buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(neg, i, char_buff, flag, width, p_mod, len));
}
