
#include "main.h"

/**
 * output_buf - Prints char_buff contents
 *
 * @char_buff: Character Array
 * @buff_ind: Pointer to index of the char_buff
 * Description: This function prints the contents of the char_buff
 * if the char_buff contains any characters. The buff_ind pointer
 * is used to keep track of the length of the char_buff.
 *
 */
void output_buf(char char_buff[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &char_buff[0], *buff_ind);
	}

	*buff_ind = 0;
}

/**
 * writ_hex - converts an unsigned integer to a hexadecimal
 * @args:va_list of arguments
 * @wid: get wid
 * @prsn: Precision specification
 * @buffer_size: character char_buff
 * @flags:  integer flags to modify the formatting
 * @charF: character flag to prepend to the outputy
 * @hard_code_var: character array of characters to map the hexadecimal value to
 * @char_buff: character char_buff
 * Return: integer char_buff size
 */



int writ_hex(va_list args, char hard_code_var[], char char_buff[],
		int flags, char charF, int wid, int prsn, int buffer_size)
{
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int fbNum = num;
	int i = BUFFER_SIZE - 2;

	num = conv_unsallid(num, buffer_size);
	VOID(wid);
	if (num == 0)
		char_buff[i--] = '0';



	char_buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		char_buff[i--] = hard_code_var[num % 16];
		num /= 16;
	}
	if (flags & FLAGSH && fbNum != 0)
	{

		char_buff[i--] = charF;
		char_buff[i--] = '0';

	}

	i++;

	return (print_ud(0, i, char_buff, flags, wid, prsn, buffer_size));
}

/**
 * write_number - writes a number to a char_buff
 *
 * @neg: 1 if the number is negative, 0 otherwise
 * @flags: flags for formatting the output
 * @mod_width: minimum mod_width of the field
 * @mod_pres: mod_pres of the field
 * @ind: the starting index of the number in the char_buff
 * @char_buff: the char_buff to write the number to

 * @size: size of the field
 *
 * Return: the number of characters written to the char_buff
 */
int write_number(int neg, int ind, char char_buff[],
		int flags, int mod_width, int mod_pres, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = (flags & FLAGZ) && !(flags & FLAGM) ? '0' : ' ';
	char extra_ch = neg ? '-' : (flags & FLAGP) ? '+' : (flags & FLAGS) ? ' ' : 0;
	VOID(size);



	return write_num(ind, char_buff, flags, mod_width, mod_pres,
			length, padd, extra_ch);

}

/**
 * write_num - formats and writes a numerical value to standard output
 * @ind: index of the buffer where to start writing\
 * @char_buff: character buffer where to write the numerical value
 *
 * @flags: integer representing the format flags
 * @mod_width: integer representing the width modifier
 * @prec: integer representing the precision modifier
 * @length: integer representing the length of the numerical value
 * @padd: character representing the padding character
 *  @spaces: character representing the extra character to be inserted in the output
 * Return: integer representing the number of characters written to standard output
 */

int write_num(int ind, char char_buff[],
		int flags, int mod_width, int prec,
		int length, char padd, char spaces)
{
	int i, start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && char_buff[ind] == '0' && mod_width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && char_buff[ind] == '0')
		char_buff[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		char_buff[--ind] = '0', length++;
	if (spaces != 0)
		length++;
	if (mod_width > length)
	{
		for (i = 1; i < mod_width - length + 1; i++)
			char_buff[i] = padd;
		char_buff[i] = '\0';
		if (flags & FLAGM && padd == ' ')
		{
			if (spaces)
				char_buff[--ind] = spaces;
			return (write(1, &char_buff[ind], length) + write(1, &char_buff[1], i - 1));
		}
		else if (!(flags & FLAGM) && padd == ' ')
		{
			if (spaces)
				char_buff[--ind] = spaces;
			return (write(1, &char_buff[1], i - 1) + write(1, &char_buff[ind], length));
		}
		else if (!(flags & FLAGM) && padd == '0')
		{
			if (spaces)
				char_buff[--start] = spaces;
			return (write(1, &char_buff[start], i - start) +
					write(1, &char_buff[ind], length - (1 - start)));
		}
	}
	if (spaces)
		char_buff[--ind] = spaces;
	return (write(1, &char_buff[ind], length));
}





