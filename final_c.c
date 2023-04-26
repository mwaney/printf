
#include "main.h"

/**
 * conv_rev - Prints reverse string.
 * @size: size of buffer (unused)
 * @args: va_list containing the string
 * @buff: Buffer array to handle print
 * @flags : unused attr
 * @wid : unused attr
 * @prsn : (unused)
 * @size : unused
 * Return: Numbers of chars printed
 */
int conv_rev(va_list args, char buff[],
int flags, int wid, int prsn, int size)
{
	int k, count = 0;
	char *string, c;

	(void)(buff);
	(void)(flags);
	(void)(wid);
	(void)(prsn);
	(void)(size);
	string = va_arg(args, char *);

	if (!string)
	{
		string = "(null)";
	}

	k = 0;
	while (string[k] != '\0')
	{
		k++;
	}

	k--;
	while (k >= 0)
	{
		c = string[k];
		write(1, &c, 1);
		count++;
		k--;
	}

	return (count);
}


/**
 * print_str - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @fla:  Calculates active fla
 * @wid: get wid.
 * @precisn: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_str(va_list args, char buffer[], int fla,
		 int wid, int precisn, int size)
{
	int length = 0, i;
	char *str;


	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (precisn >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;

	if (precisn >= 0 && precisn < length)
		length = precisn;

	if (wid > length)
	{
		if (fla & FLAGM)
		{
			write(1, &str[0], length);
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}
	VOID(wid);
	VOID(precisn);
	VOID(size);
	VOID(buffer);
	VOID(fla);
	return (write(1, str, length));
}

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	VOID(precision);
	VOID(size);

	if (flags & FLAGZ)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = padd;

		if (flags & FLAGM)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
