#include "main.h"

/**
 * print_ptr - Prints the value of a pointer variable
 *
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get wid
 * @prsn: Precision specification
 * @buffer_size: Size specifier
 *
 * Return: Number of chars printed.
 */

int print_ptr(va_list args, char buffer[],
		int flags, int wid, int prsn, int buffer_size)
{
	char padding = 0, padd = ' ';
	void *addrs = va_arg(args, void *);
	uintptr_t addr;
	int pref;
	int len;

	char hard_code_var[] = "0123456789abcdef";


	pref = BUFFER_SIZE - 2;
	len = 2;

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	addr = (uintptr_t)addrs;
	while (addr > 0)
	{
		buffer[pref--] = hard_code_var[addr % 16];
		addr /= 16;
		len++;
	}
	if ((flags & FLAGZ) && !(flags & FLAGM))
		padd = '0';
	if (flags & FLAGP)
		padding = '+', len++;
	else if (flags & FLAGS)
		padding = ' ', len++;

	pref++;

	VOID(prsn);
	VOID(wid);
	VOID(buffer_size);

	return (write_ptr(buffer, pref, len, wid, flags, padd, padding, 1));
}

/**
 * print_up_hex - Prints an unsigned number in upper hexadecimal notation
 * @args: Lista of arguments
 * @wid: get wid
 * @prsn: Precision specification
 * @buffer_size: Size specifier
 *
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_up_hex(va_list args, char buffer[],
		int flags, int wid, int prsn, int buffer_size)
{
	return (writ_hex(args, "0123456789ABCDEF", buffer,
				flags, 'X', wid, prsn, buffer_size));
}
/**
 * print_hex - prints a hexadecimal value to a character buffer
 * @args: va_list of arguments
 * @buffer: character buffer to write the formatted output to
 * @flags:  integer flags to modify the formatting
 * @wid: integer wid for minimum field wid
 * @prsn: integer prsn for minimum number of digits
 * @buffer_size: integer buffer len
 *
 * Return: integer value
 */
int print_hex(va_list args, char buffer[],
		int flags, int wid, int prsn, int buffer_size)
{
	return (writ_hex(args, "0123456789abcdef", buffer,
				flags, 'x', wid, prsn, buffer_size));
}

/**
 * print_str - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @fla:  Calculates active fla
 * @wid: get wid.
 * @precisn: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */

int print_perc(va_list args, char buffer[],
		int fla, int wid, int precisn, int len)
{
	VOID(wid);
	VOID(precisn);

	VOID(buffer);
	VOID(fla);
	VOID(len);
	VOID(args);

	return (write(1, "%%", 1));

}

/**
 * print_c -formats and prints a single character to a buffer
 *
 * @wid: Width
 * @precisn: number of digits after the decimal point
 * @args: va_list of arguments
 * @buffer: a character buffe
 * @fla:  ormatting flags
 * @len: maximum len
 *
 * Return: number of characters written to the bufferd
 */

int print_c(va_list args, char buffer[],
		int fla, int wid, int precisn, int len)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, fla, wid, precisn, len));
}

