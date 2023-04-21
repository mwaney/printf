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

#endif
