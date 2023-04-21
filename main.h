#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_num(int x, int *count);
void print_char(char c, int *count);
const char *handle_switch(const char *string, va_list argList, int *count);
void print_str(const char *s, int *count);
void print_bin(unsigned int n, int *count);
void print_ud(unsigned int num, int *count);
void print_oct(unsigned int num, int *count);
void print_hex(unsigned int num, int uppercase, int *count);
#endif
