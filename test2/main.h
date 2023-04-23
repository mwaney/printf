#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
const char *handle_switch(const char *string, va_list argList,
		int *count, char *buffer, int *buf_index);
void print_buffer(char *buffer, int *bufferIndex, int *count);
void print_char_to_buffer(char *buffer, int *bufferIndex, char c);
void print_str_to_buffer(char *buffer, int *bufferIndex, const char *str);
void print_num_to_buffer(char *buffer, int *bufferIndex, int num);
void print_bin_to_buffer(char *buffer, int *bufferIndex, unsigned int num);
void print_ud_to_buffer(char *buffer, int *bufferIndex, unsigned int num);
void print_oct_to_buffer(char *buffer, int *bufferIndex, unsigned int num);
void print_hex_to_buffer(char *buffer, int *bufferIndex,
		unsigned int num, int uppercase);
void print_percent_to_buffer(char *buffer, int *bufferIndex);
void print_custom_str(char *buffer, int *buf_index, const char *str);
#endif
