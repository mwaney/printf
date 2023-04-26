

#ifndef PRINT_F
#define PRINT_F

#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>



#define VOID(x) (void)(x)
#define BUFFER_SIZE 1024
#define FLAGS 16
#define SLS 2
#define CLS 1
#define FLAGM 1
#define FLAGP 2
#define FLAGZ 4
#define FLAGSH 8

/**
 * struct format_specifier - Struct for format specifiers
 *
 * @format_spec: The format specifier
 * @fn: The function associated with the format specifier
 */
typedef struct format_specifier
{
	char format_spec;
	int (*fn)(va_list, char[], int, int, int, int);
} fm_struct;

int print_str(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_perc(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int writ_hex(va_list args, char map_to[],
		char buffer[], int flags, char flag_ch, int wid, int p, int cs);
int _printf(const char *format, ...);
int handle_format_spec(const char *format_spec, int *i,
		va_list list, char buffer[], int flags, int wid, int p, int cs);


int print_up_hex(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_c(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_ptr(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int conv_rot13(va_list args, char buffer[],
		int flags, int wid, int p, int cs);

int handle_write_char(char c, char buffer[],
		int flags, int wid, int p, int cs);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int wid, int p, int cs);
int write_num(int ind, char bff[], int flags, int wid, int p,
		int length, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int length,
		int wid, int flags, char padd, char extra_c, int padd_start);

int print_ud(int is_negative, int ind,
		char buffer[],
		int flags, int wid, int p, int cs);

int bool_print(char);
int prefix_hex(char, char[], int);
int bool_digit(char);

long int change_num_size(long int num, int cs);
long int conv_unsallid(unsigned long int num, int cs);

int flagged(const char *format, int *i);
int wide(const char *format, int *i, va_list list);
int print_precision(const char *format, int *i, va_list list);
int sizef(const char *format, int *i);
int conv_rev(va_list args, char buffer[],
		int flags, int wid, int p, int cs);

int print_int(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_bin(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_unsalid(va_list args, char buffer[],
		int flags, int wid, int p, int cs);

int print_oct(va_list args, char buffer[],
		int flags, int wid, int p, int cs);
int print_hex(va_list args, char buffer[],
		int flags, int wid, int p, int cs);

int writ_S(va_list args, char buffer[],
		int flags, int wid, int p, int cs);


#endif /* MAIN_H */

