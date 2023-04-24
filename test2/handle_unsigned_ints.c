#include "main.h"
/**
 * print_ud - prints an unsigned integer
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * @base: base to use for conversion
 * @uppercase: whether to use uppercase for x/X
 * Return: updated index in buffer
 */
int print_ud(va_list args, char *buffer, int buffer_index,
		int buff_size, unsigned int base, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char digits[] = "0123456789abcdef";
	char num_buffer[40];
	int num_index = 0;
	int i;
	int chars_printed = 0;

	while (num != 0)
	{
		num_buffer[num_index++] = digits[num % base];
		num /= base;
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
 * print_octal - prints an unsigned integer in octal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_octal(va_list args, char *buffer, int buffer_index,
		int buff_size)
{
	return (print_ud(args, buffer, buffer_index, buff_size, 8, 0));
}

/**
 * print_hex - prints an unsigned integer in lowercase hexadecimal format
 * @args: va_list of arguments
 * @buffer: buffer to store output
 * @buffer_index: current index in buffer
 * @buff_size: size of buffer
 * Return: updated index in buffer
 */
int print_hex(va_list args, char *buffer, int buffer_index,
		int buff_size)
{
	return (print_ud(args, buffer, buffer_index, buff_size, 16, 0));
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
	return (print_ud(args, buffer, buffer_index, buff_size, 16, 1));
}

