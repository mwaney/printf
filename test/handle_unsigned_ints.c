#include "main.h"

/**
 * print_decimal - prints an unsigned decimal integer
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * @flag: flag character to handle
 * Return: updated index in buffer
 */
int print_decimal(va_list args, char *buffer, int buffer_index, int buff_size, char *flags)
{
    unsigned int num = va_arg(args, unsigned int);
    char num_buffer[12];
    int num_index = 0;
    int i;
    int chars_printed = 0;
    int has_sign = 0;

    if (strcmp(flags, "+") == 0)
    {
        has_sign = 1;
    }
    else if (strcmp(flags, " ") == 0)
    {
        has_sign = 2;
    }

    if (num == 0)
    {
        buffer[buffer_index++] = '0';
        if (has_sign)
        {
            buffer[buffer_index++] = (has_sign == 1) ? '+' : ' ';
        }
    }
    else
    {
        while (num != 0)
        {
            num_buffer[num_index++] = (num % 10) + '0';
            num /= 10;
        }

        if (has_sign)
        {
            buffer[buffer_index++] = (has_sign == 1) ? '+' : ' ';
        }

        for (i = num_index - 1; i >= 0; i--)
        {
            buffer[buffer_index++] = num_buffer[i];
            if (buffer_index >= buff_size)
            {
                write_buffer(buffer, buff_size, &chars_printed, &buffer_index);
            }
        }
    }

    return buffer_index;
}


/**
 * print_octal - prints an unsigned integer in octal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_octal(va_list args, char *buffer, int buffer_index, int buff_size)
{
	unsigned int num = va_arg(args, unsigned int);
	char num_buffer[12];
	int num_index = 0;
	int i;
	int chars_printed = 0;

	if (num == 0)
	{
		buffer[buffer_index++] = '0';
	}
	else
	{
		while (num != 0)
		{
			num_buffer[num_index++] = (num % 8) + '0';
			num /= 8;
		}

		for (i = num_index - 1; i >= 0; i--)
		{
			buffer[buffer_index++] = num_buffer[i];
			if (buffer_index >= buff_size)
			{
				write_buffer(buffer, buff_size, &chars_printed, &buffer_index);
			}
		}
	}

	return (buffer_index);
}
/**
 * print_hex - prints an unsigned integer in lowercase or uppercase
 *             hexadecimal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * @uppercase: 1 to use uppercase letters, 0 for lowercase
 * Return: updated index in buffer
 */
int print_hex(va_list args, char *buffer, int buffer_index,
		int buff_size, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char digits[] = "0123456789abcdef";
	char num_buffer[40];
	int num_index = 0;
	int i;
	int chars_printed = 0;

	while (num != 0)
	{
		num_buffer[num_index++] = digits[num % 16];
		num /= 16;
	}

	if (uppercase)
	{
		for (i = 0; i < num_index; i++)
		{
			num_buffer[i] = toupper(num_buffer[i]);
		}
	}

	for (i = num_index - 1; i >= 0; i--)
	{
		buffer[buffer_index++] = num_buffer[i];
		if (buffer_index >= buff_size)
		{
			write_buffer(buffer, buff_size, &chars_printed, &buffer_index);
		}
	}

	return (buffer_index);
}

/**
 * print_hex_lowercase - prints an unsigned integer
 * in lowercase hexadecimal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_hex_lowercase(va_list args, char *buffer, int buffer_index,
		int buff_size)
{
	return (print_hex(args, buffer, buffer_index, buff_size, 0));
}

/**
 * print_hex_uppercase - prints an unsigned integer
 * in uppercase hexadecimal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_hex_uppercase(va_list args, char *buffer, int buffer_index,
		int buff_size)
{
	return (print_hex(args, buffer, buffer_index, buff_size, 1));
}






