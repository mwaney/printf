#include "main.h"

int print_string(va_list args, char *buffer, int buffer_index, int buff_size,
		int width, int precision, char *flags)
{
	char *s = va_arg(args, char *);
	char pad_char;
	int len = strlen(s);
	int print_len = (precision >= 0 && precision < len) ? precision : len;
	int field_len = print_len;
	int pad_len;
	if (s == NULL)
	{
		s = "(null)";
	}

	if (width > field_len)
	{
		pad_char = (flags && strchr(flags, '0')) ? '0' : ' ';
		pad_len = width - field_len;
		while (pad_len--)
		{
			if (buffer_index < buff_size - 1)
			{
				buffer[buffer_index++] = pad_char;
			}
		}
	}

	if (buffer_index < buff_size - 1)
	{
		strncpy(buffer + buffer_index, s, print_len);
	}

	return field_len;
}

int print_integer(va_list args, char *buffer, int buffer_index, int buff_size,
		int width, int precision, char *flags)
{
	int num = va_arg(args, int);
	char num_buffer[12], pad_char, zeros_to_add, num_len;
	int num_index = 0;
	int chars_printed = 0;
	int is_negative = 0;
	int i, pad_len;

	if (num == 0)
	{
		buffer[buffer_index++] = '0';
	}
	else
	{
		if (num < 0) {
			is_negative = 1;
			num = -num;
		}

		while (num != 0)
		{
			num_buffer[num_index++] = (num % 10) + '0';
			num /= 10;
		}

		if (is_negative) {
			num_buffer[num_index++] = '-';
		}
	}

	num_len = num_index;

	if (precision > num_len)
	{
		zeros_to_add = precision - num_len;
		while (zeros_to_add--)
		{
			if (buffer_index < buff_size - 1)
			{
				buffer[buffer_index++] = '0';
			}
		}
	}

	if (width > num_len + is_negative + precision)
	{
		pad_char = (flags && strchr(flags, '0')) ? '0' : ' ';
		pad_len = width - num_len - is_negative - precision;
		while (pad_len--)
		{
			if (buffer_index < buff_size - 1)
			{
				buffer[buffer_index++] = pad_char;
			}
		}
	}

	for (i = num_index - 1; i >= 0; i--)
	{
		if (buffer_index < buff_size - 1)
		{
			buffer[buffer_index++] = num_buffer[i];
		}
	}

	chars_printed += num_len + is_negative;

	return chars_printed;
}
int print_chars(va_list args, char *buffer, int buffer_index, int buff_size,
		int width, int precision __attribute__((unused))#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_chars(va_list args, char *buffer, int buffer_index, int buff_size, int width, int precision, char *flags);
int print_string(va_list args, char *buffer, int buffer_index, int buff_size,
                int width, int precision, char *flags);
int print_integer(va_list args, char *buffer, int buffer_index, int buff_size,
                int width, int precision, char *flags);
void write_buffer(const char *buffer, int size, int *chars_printed, int *buffer_index);
int print_percent(char *buffer, int width, const char *flags);
int print_character(va_list args, char *buffer, int width, const char *flags);
int handle_format_specifier(const char *format, va_list args, char *buffer, int *buffer_index, int buffer_size, int *chars_printed);
int handle_conversion_specifier(char specifier, va_list args, char *buffer, int *buffer_index, int buffer_size, int width, int precision, const char *flags);
int handle_format_specifier(const char *format, va_list args, char *buffer,
                            int *buffer_index, int buff_size, int *chars_printed);
int get_number(const char **format);
#endif, char *flags)
{
	char c = va_arg(args, int);

	int specifier_size = 1; 

	if (width > 0)
	{
		specifier_size = width;
		if (flags[0] != '-')
		{
			while (specifier_size > 1 && buffer_index < buff_size - 1)
			{
				buffer[buffer_index++] = ' ';
				specifier_size--;
			}
		}
		if (specifier_size > 1 && buffer_index < buff_size - 1)
		{
			buffer[buffer_index++] = c;
			specifier_size--;
		}
		while (specifier_size > 1 && buffer_index < buff_size - 1)
		{
			buffer[buffer_index++] = ' ';
			specifier_size--;
		}
	}
	else
	{
		if (buffer_index < buff_size - 1)
		{
			buffer[buffer_index++] = c;
		}
	}

	buffer[buffer_index] = '\0';

	return (specifier_size);
}

