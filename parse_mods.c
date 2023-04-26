#include "main.h"

/**
 * flagged - flag for conversion specifiers
 * @format: string to checktring to check
 * @i:  index
 * Return: integer representing the active flags based on the format string
 *
 * Description: This function analyzes the format string to determine which
 * flags are active. It returns an integer value that represents the active
 * flags based on the values found in the format string.
 */

int flagged(const char *format, int *i)
{
	int active_flag = 0;
	int curr_i = *i + 1;

	const int FLAGS_ARR[] = {FLAGM, FLAGP, FLAGZ, FLAGSH, FLAGS, 0};
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	while (format[curr_i] != '\0')
	{
		int j = 0;

		while (FLAGS_CH[j] != '\0')
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				active_flag |= FLAGS_ARR[j];
				break;
			}
			j++;
		}

		if (FLAGS_CH[j] == 0)
			break;

		curr_i++;
	}

	*i = curr_i - 1;

	return (active_flag);
}


