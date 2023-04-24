#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...);
int print_char(va_list args, char *buffer, int buffer_index);
int print_string(va_list args, char *buffer, int buffer_index, int buff_size);
void write_buffer(char *buffer, int buffer_size,
		int *chars_printed, int *buffer_index);
int handle_format_specifier(const char *format, va_list args,
		char *buffer, int *buffer_index, int buff_size,
		int *chars_printed);
void print_buffered_string(const char *format, va_list args,
		char *buffer, int *buffer_index, int buff_size,
		int *chars_printed);
int print_integer(va_list args, char *buffer, int buffer_index, int buff_size);
#endif
