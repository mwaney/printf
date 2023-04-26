#ifndef MAIN_H
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
#endif
