

#include "main.h"



int print_ud(int neg, int ind,
		char char_buff[],
		int fl, int wid, int prsn, int len)
{

	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padd = ' ';

	VOID(neg);
	VOID(len);

	if (prsn == 0 && ind == BUFFER_SIZE - 2 && char_buff[ind] == '0')
		return (0);

	if (prsn > 0 && prsn < length)
		padd = ' ';

	while (prsn > length)
	{
		char_buff[--ind] = '0';
		length++;
	}

	if ((fl & FLAGZ) && !(fl & FLAGM))
		padd = '0';

	if (wid > length)
	{
		for (i = 0; i < wid - length; i++)
			char_buff[i] = padd;

		char_buff[i] = '\0';

		if (fl & FLAGM)
		{
			return (write(1, &char_buff[ind], length) + write(1, &char_buff[0], i));
		}
		else
		{
			return (write(1, &char_buff[0], i) + write(1, &char_buff[ind], length));
		}
	}

	return (write(1, &char_buff[ind], length));
}

int write_ptr(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FLAGM && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FLAGM) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FLAGM) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

