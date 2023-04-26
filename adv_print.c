#include "main.h"



/**
 * conv_rot13 - rot13 string.
 * @args: va_list containing the string
 * @buff: buffer
 * @flags: flags
 * @wid: width
 * @prsn: precision
 * @size: size
 * Return: integer count
 *
 */

int conv_rot13(va_list args, char buff[],
		int flags, int wid, int prsn, int size)
{
	int i;
	char x;
	char *p;
	int counter = 0;
	char orig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	p = va_arg(args, char *);
	VOID(buff);
	VOID(flags);
	VOID(wid);
	VOID(prsn);
	VOID(size);

	if (!p)
	{
		p = "(null)";
	}

	if (*p)
	{
		for (i = 0; orig[i]; i++)
		{
			if (orig[i] == *p)
			{
				x = rot[i];
				write(1, &x, 1);
				counter++;
				break;
			}
		}

		if (!orig[i])
		{
			x = *p;
			write(1, &x, 1);
			counter++;
		}

		counter += conv_rot13(args, buff, flags, wid, prsn, size);
	}

	return counter;
}
/**
 * writ_S - rites a string with hex values
 *
 * @size: size of buffer (unused)
 * @args: va_list containing the string
 * @buff: Buffer array to handle print
 * @flags: (unused)
 * @wid: (unused)
 * @prsn: (unused)
 * Return: integer
 */


int writ_S(va_list args, char buff[],
		int flags, int wid, int prsn, int size)
{
	int i = 0, pref = 0;
	char *p = va_arg(args, char *);

	VOID(flags);
	VOID(wid);
	VOID(prsn);
	VOID(size);

	if (!p)
		return (write(1, "(null)", 6));

	for (i = 0; p[i] != '\0'; i++)
	{
		if (bool_print(p[i]))
			buff[i + pref] = p[i];
		else
			pref += prefix_hex(p[i], buff, i + pref);


	}

	buff[i + pref] = '\0';
	return (write(1, buff, i + pref));
}
